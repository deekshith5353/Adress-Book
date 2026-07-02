# Address Book Management System

## Overview

The Address Book Management System is a console-based application developed in C for managing contact information. It provides essential contact management operations including adding, viewing, searching, editing, and deleting records. Contact data is stored in a CSV file, ensuring persistence across program executions.

---

## Features

* Add new contacts
* View all saved contacts
* Search contacts by name
* Edit existing contact details
* Delete contacts
* Automatic data saving
* Load contacts from a CSV file at startup

---

## Technologies Used

* C Programming Language
* GCC Compiler
* File Handling
* Structures
* Modular Programming
* CSV File Storage
* Makefile

---

## Project Structure

```text
AddressBook/
│── main.c
│── contacts.c
│── contacts.h
│── contacts.csv
│── Makefile
│── README.md
```

---

## Functional Modules

### Add Contact

Stores a new contact by accepting the user's name, phone number, and email address.

### View Contacts

Displays all contacts stored in the address book.

### Search Contact

Searches for a contact using the contact name.

### Edit Contact

Updates the phone number and email address of an existing contact.

### Delete Contact

Removes a contact permanently from the address book.

---

## Data Storage

All contact information is stored in a CSV file using the following format:

```text
Name,Phone,Email
```

Example:

```text
John Doe,9876543210,john@example.com
Jane Smith,9123456789,jane@gmail.com
```

---

## Building the Project

Compile using the provided Makefile:

```bash
make
```

Alternatively, compile manually:

```bash
gcc main.c contacts.c -o addressbook
```

---

## Running the Application

Linux/macOS

```bash
./addressbook
```

Windows

```bash
addressbook.exe
```

---

## Menu Options

```text
1. Add Contact
2. View Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
```

---

## Concepts Demonstrated

* Structures
* Arrays
* File Handling
* Modular Programming
* Header Files
* String Manipulation
* CRUD Operations
* CSV Data Management

---

## Future Enhancements

* Input validation for phone numbers and email addresses
* Duplicate contact detection
* Contact sorting
* Search by phone number or email
* Password-protected access
* Dynamic memory allocation
* Improved terminal interface

---

## Author

**Deekshith**

