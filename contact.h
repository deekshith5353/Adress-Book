#ifndef CONTACT_H
#define CONTACT_H
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[93m"
#define BLUE    "\033[94m"
#define RESET   "\033[0m"
#define MAX_CONTACTS 100
extern int Index[MAX_CONTACTS];
extern int z;

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

#endif
