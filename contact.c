#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"

int Index[MAX_CONTACTS];
int z = 0;

int is_name(char str[])
{
    int count = 0;
name:
    {
        int valid = 1;
        if (isdigit((unsigned char)str[0])) {
            printf("\t\033[31mError : First charactor must be alphabet\n" RESET);
            valid = 0;
        }
        if (strlen(str) < 4) {
            valid = 0;
            printf("\t\033[31mError : Name must contain atleast 4 characters\n" RESET);
        }
        for (int i = 0; str[i] != '\0'; i++) {
            if (!isalpha((unsigned char)str[i]) && str[i] != ' ') {
                printf("\t\033[31mError : Name cannot contain special characters or digits\n" RESET);
                valid = 0;
                break;
            }
        }
        if (count >= 3) {
            printf("\t\033[31mError :To many invalid attempts\n" RESET);
            return 0;
        }
        if (!valid) {
            printf("\tEnter again: ");
            scanf(" %49[^\n]", str);
            count++;
            goto name;
        }
        return 1;
    }
}

int is_phone(char str[])
{
    int count = 0;
phone:
    {
        int valid = 1;
        if (strlen(str) != 10) {
            valid = 0;
            printf("\t\033[31mError :Number should have 10 digits\n" RESET);
        }
        if (str[0] < '6' || str[0] > '9') {
            valid = 0;
            printf("\t\033[31mError :First digit must be between 6 and 9\n" RESET);
        }
        for (int i = 0; str[i] != '\0'; i++) {
            if (!isdigit((unsigned char)str[i])) {
                valid = 0;
                printf("\t\033[31mError :Only digits are allowed in phone number\n" RESET);
                break;
            }
        }
        if (count >= 3) {
            printf("\t\033[31mError :Too many invalid attempts\n" RESET);
            return 0;
        }
        if (!valid) {
            printf("\t Enter again: ");
            scanf(" %19[^\n]", str);
            count++;
            goto phone;
        }
        return 1;
    }
}

int is_email(char str[])
{
    int count = 0;
email:
    {
        int valid = 1;
        int at = 0, dot = 0;
        int at_pos = -1, dot_pos = -1;

        if (isdigit((unsigned char)str[0])) {
            printf("\t\033[31mError :First charactor should be alphabet\n" RESET);
            valid = 0;
        }
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '@') {
                at++;
                at_pos = i;
            } else if (str[i] == '.') {
                dot++;
                dot_pos = i;
            } else if (!(islower((unsigned char)str[i]) || isdigit((unsigned char)str[i]))) {
                printf("\t\033[31mError :email needs to be in lower case and cannot contain any special charactors other than @ and .\n" RESET);
                valid = 0;
                break;
            }
        }
        if (at != 1) {
            printf("\t\033[31mError :only one @ is allowed\n" RESET);
            valid = 0;
        }
        if (dot != 1 || dot_pos < at_pos) {
            printf("\t\033[31mError :only one . is allowed and . can appear only after @ \n" RESET);
            valid = 0;
        }
        if (at_pos == 0) valid = 0;
        if (dot_pos == at_pos + 1) {
            printf("\t\033[31mError :Domain not found\n" RESET);
            valid = 0;
        }
        if (valid) {
            for (int i = at_pos + 1; i < dot_pos; i++) {
                if (!isalpha((unsigned char)str[i])) {
                    printf("\t\033[31mError :Domain can only be of alphabets\n" RESET);
                    valid = 0;
                    break;
                }
            }
        }
        if (strlen(str) < 5 || strcmp(str + strlen(str) - 4, ".com") != 0) {
            valid = 0;
            printf("\t\033[31mError :email should end with .com\n" RESET);
        }
        if (count >= 3) {
            printf("\t\033[31mError :Too many invalid attempts\n" RESET);
            return 0;
        }
        if (!valid) {
            printf("\tEnter again: ");
            scanf(" %49[^\n]", str);
            count++;
            goto email;
        }
        return 1;
    }
}

int duplicate_phone(AddressBook *addressBook, char phone[])
{
    int count = 0;
    while (count < 3) {
        int found = 0;
        for (int i = 0; i < addressBook->contactCount; i++) {
            if (strcmp(addressBook->contacts[i].phone, phone) == 0) {
                printf("\tphone number already exists! Enter again: ");
                scanf(" %19[^\n]", phone);
                if (!is_phone(phone)) {
                    printf("\033[31mError:Too many Invalid attempts" RESET);
                    return 1;
                }
                found = 1;
                count++;
                break;
            }
        }
        if (!found) return 0;
    }
    printf("\033[31mError:Too many Invalid attempts" RESET);
    return 1;
}

int duplicate_email(AddressBook *addressBook, char email[])
{
    int count = 0;
    while (count < 3) {
        int found = 0;
        for (int i = 0; i < addressBook->contactCount; i++) {
            if (strcmp(addressBook->contacts[i].email, email) == 0) {
                printf("\tEmail already exists! Enter again: ");
                scanf(" %49[^\n]", email);
                if (!is_email(email)) {
                    printf("\033[31mError:Too many Invalid attempts" RESET);
                    return 1;
                }
                found = 1;
                count++;
                break;
            }
        }
        if (!found) return 0;
    }
    printf("\033[31mError:Too many Invalid attempts" RESET);
    return 1;
}

void listContacts(AddressBook *addressBook)
{
    printf(YELLOW "\tLIST CONTACTS MENU" RESET);
    printf("\tSelect sort criteria:\n");
    printf("\t1. Sort by name\n");
    printf("\t2. Sort by phone\n");
    printf("\t3. Sort by email\n");
    printf("\t4. Exit\n");
    printf("\tEnter your choice: ");
    int sortChoice;
    scanf("%d", &sortChoice);

    switch (sortChoice) {
    case 1:
        printf("Sorting by name : \n");
        for (int i = 0; i < addressBook->contactCount - 1; i++)
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
                if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
        break;
    case 2:
        printf("Sorting by phone : \n");
        for (int i = 0; i < addressBook->contactCount - 1; i++)
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
                if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
        break;
    case 3:
        printf("Sorting by email : \n");
        for (int i = 0; i < addressBook->contactCount - 1; i++)
            for (int j = 0; j < addressBook->contactCount - i - 1; j++)
                if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
        break;
    default:
        return;
    }

    printf("No\tName\t\tPhone\t\tEmail\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < addressBook->contactCount; i++)
        printf("%d\t%-15s\t%-10s\t%s\n", i + 1,
               addressBook->contacts[i].name, addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS);
}

void createContact(AddressBook *addressBook)
{
    char name[100], phone[100], email[100];
    if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Address book is full.\n");
        return;
    }
    printf(YELLOW "\tCREATE CONTACT MENU\n" RESET);
    printf("\tEnter the Name:");
    scanf(" %99[^\n]", name);
    if (!is_name(name)) return;

    printf("\tEnter the Phone Number:");
    scanf(" %99[^\n]", phone);
    if (!is_phone(phone)) return;
    if (duplicate_phone(addressBook, phone)) return;

    printf("\tEnter the email:");
    scanf(" %99[^\n]", email);
    if (!is_email(email)) return;
    if (duplicate_email(addressBook, email)) return;

    printf("\033[32mCreated Successfully" RESET);
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    addressBook->contactCount++;
}

int searchContact(AddressBook *addressBook)
{
    printf("\tSelect search criteria:\n");
    printf("\t1.search by name\n");
    printf("\t2.search by phone\n");
    printf("\t3.search by email\n");
    printf("\t4.Exit\n");
    printf("\tEnter your choice: ");
    int searchChoice;
    scanf("%d", &searchChoice);
    char str[50];

    switch (searchChoice) {
    case 1:
        printf("\tEnter name:");
        scanf(" %49[^\n]", str);
        if (!is_name(str)) return 1;
        z = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
            if (strcmp(addressBook->contacts[i].name, str) == 0) Index[z++] = i;
        if (z == 0) printf("\tNot found!!\n");
        break;
    case 2:
        printf("\tEnter Phone Number:");
        scanf(" %49[^\n]", str);
        if (!is_phone(str)) return 1;
        z = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
            if (strcmp(addressBook->contacts[i].phone, str) == 0) Index[z++] = i;
        if (z == 0) printf("\tNot found!!\n");
        break;
    case 3:
        printf("\tEnter Email:");
        scanf(" %49[^\n]", str);
        if (!is_email(str)) return 1;
        z = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
            if (strcmp(addressBook->contacts[i].email, str) == 0) Index[z++] = i;
        if (z == 0) printf("\tNot found!!\n");
        break;
    default:
        return 1;
    }
    return 0;
}

void editContact(AddressBook *addressBook)
{
    if (searchContact(addressBook)) return;
    for (int i = 0; i < z; i++)
        printf(" \t%d  %s\t%s\t%s\n", i + 1,
               addressBook->contacts[Index[i]].name,
               addressBook->contacts[Index[i]].phone,
               addressBook->contacts[Index[i]].email);

    char temp[50];
    int ind = 0, choice;
    printf("\tEnter the Index of the contact you want to edit:");
    scanf("%d", &ind);
    if (ind < 1 || ind > z) {
        printf("\tInvalid index\n");
        return;
    }
    printf("\tChoose what do u want to edit\n\t1.Name\n\t2.Phone no\n\t3.Email\n\t4.Exit\n");
    printf("Enter choice:");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("\tEnter the New name:");
        scanf(" %49[^\n]", temp);
        if (!is_name(temp)) return;
        strcpy(addressBook->contacts[Index[ind - 1]].name, temp);
        break;
    case 2:
        printf("\tEnter the New Phone No:");
        scanf(" %49[^\n]", temp);
        if (!is_phone(temp)) return;
        if (duplicate_phone(addressBook, temp)) return;
        strcpy(addressBook->contacts[Index[ind - 1]].phone, temp);
        break;
    case 3:
        printf("\tEnter the New Email:");
        scanf(" %49[^\n]", temp);
        if (!is_email(temp)) return;
        if (duplicate_email(addressBook, temp)) return;
        strcpy(addressBook->contacts[Index[ind - 1]].email, temp);
        break;
    default:
        return;
    }
    printf("Edit Successfull!!");
}

void deleteContact(AddressBook *addressBook)
{
    printf(YELLOW "\tDELETE CONTACT MENU\n" RESET);
    if (searchContact(addressBook)) return;
    for (int i = 0; i < z; i++)
        printf(" \t%d  %s\t%s\t%s\n", i + 1,
               addressBook->contacts[Index[i]].name,
               addressBook->contacts[Index[i]].phone,
               addressBook->contacts[Index[i]].email);

    int ind = 0;
    printf("\tEnter the Index of the contact you want to delete:");
    scanf("%d", &ind);
    if (ind < 1 || ind > z) {
        printf("\t\033[31mInvalid index\n" RESET);
        return;
    }
    char ch;
    printf("\033[34mAre you sure you want to delete this contact Yes or No (y/n): " RESET);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') {
        for (int j = Index[ind - 1]; j < addressBook->contactCount - 1; j++)
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        addressBook->contactCount--;
        printf("\033[32mDelete Successfull!!\n" RESET);
    } else {
        printf("\033[31mDelete Canceled!" RESET);
    }
}
