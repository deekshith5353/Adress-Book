#include <stdio.h>
#include "contact.h"
#include <unistd.h>

int main(void)
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook);

    do
    {
        printf("\033[94m\nADDRESS BOOK MENU\n\033[0m");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            default:
                printf("Invalid choice. Please try again.\n");
                break;
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                printf("\033[33m\tSEARCH CONTACT MENU\033[0m\n");
                searchContact(&addressBook);
                for (int i = 0; i < z; i++)
                {
                    printf(" \t%d  %s\t%s\t%s\n", i + 1,
                           addressBook.contacts[Index[i]].name,
                           addressBook.contacts[Index[i]].phone,
                           addressBook.contacts[Index[i]].email);
                }
                break;
            case 3:
                printf("\033[33m\tEDIT CONTACT MENU\033[0m\n");
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                listContacts(&addressBook);
                break;
            case 6:
                for (int i = 0; i <= 100; i++)
                {
                    printf("\rSaving.....");
                    printf("%d%%", i);
                    fflush(stdout);
                    usleep(10000);
                }
                printf("\nSaved succesfully");
                saveContactsToFile(&addressBook);
                break;
        }
    } while (choice != 6);

    return 0;
}
