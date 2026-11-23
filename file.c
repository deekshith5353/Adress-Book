#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.csv", "w");
    int i;
    if (fp == NULL) return;
    fprintf(fp, "#%d\n", addressBook->contactCount);
    for (i = 0; i < addressBook->contactCount; i++)
        fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name,
                addressBook->contacts[i].phone, addressBook->contacts[i].email);
    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.csv", "r");
    if (fp == NULL) return;
    fscanf(fp, "#%d\n", &addressBook->contactCount);
    addressBook->contactCount = 0;
    while (addressBook->contactCount < MAX_CONTACTS &&
           fscanf(fp, " %49[^,],%19[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
        addressBook->contactCount++;
    fclose(fp);
}
