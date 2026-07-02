#ifndef CONTACTS_H
#define CONTACTS_H
struct Contact{
char name[50];
char phone[20];
char email[50];
};
extern struct Contact c[100];
extern int count;
void loadContacts();
void saveContacts();
void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
#endif
