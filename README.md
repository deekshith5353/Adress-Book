# Address Book Management System

A menu-driven, terminal-based Address Book Management System developed in C. It manages contact records and stores them in a CSV file so that saved contacts can be loaded again when the program starts.

## Features

- Create contacts with a name, phone number, and email address
- Validate name, phone number, and email input
- Check for duplicate phone numbers and email addresses
- Search contacts by name, phone number, or email address
- Edit a contact's name, phone number, or email address
- Delete contacts after confirmation
- List contacts sorted by name, phone number, or email address
- Load and save contacts using a CSV file
- Menu-driven interface with terminal colour output

## Project Structure

```text
Adress-Book/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.csv
└── README.md
```

## Technologies and Concepts

- C programming
- Structures and fixed-size arrays
- Modular programming with source and header files
- String handling and input validation
- Searching and sorting
- File handling using standard C I/O
- CSV-based persistent storage

## Compilation

Compile the project using GCC:

```bash
gcc main.c contact.c file.c -o addressbook
```

The program uses `unistd.h` and `usleep()` for the exit animation, so the supplied source is intended for Linux/Unix-like environments.

## Run

```bash
./addressbook
```

Run the executable from the project directory so that it can read and write `contacts.csv`.

## Program Menu

```text
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
```

## Contact Fields

Each contact contains:

- Name
- Phone number
- Email address

## Input Validation

The program applies the following checks:

- Names must contain at least four characters, start with a non-digit, and contain only alphabetic characters and spaces.
- Phone numbers must contain ten digits and start with a digit from 6 to 9.
- Email addresses must be lowercase, start with an alphabetic character, contain one `@` and one `.`, and end with `.com`. The domain portion between `@` and `.` is restricted to alphabets.
- Duplicate phone numbers and email addresses are rejected.

## Search, Edit, Delete, and Sorting

Contacts can be searched using an exact name, phone number, or email address. Search results are stored by index so that the selected record can be edited or deleted. Editing supports all three contact fields. The list operation offers sorting by name, phone number, or email address.

## Data Storage

Contact records are stored in `contacts.csv`. The file begins with a record count in the form `#N`, followed by one comma-separated record per line:

```text
#1
John,9876543210,john@example.com
```

The repository's CSV file is initialized with `#0` so it contains no personal contact records. New contacts are written when the program exits.

## Current Implementation Notes

- The address book uses a fixed array with a maximum capacity of 100 contacts.
- Search uses exact string matching.
- CSV fields are comma-separated and are not escaped.
- The input validation rules are intentionally simple and are not a complete validation of every possible real-world name, phone number, or email address.
- The exit animation uses `usleep()`, which is POSIX-specific.

## Author

**Deekshith**  
BE Electronics Engineering  
Nitte Meenakshi Institute of Technology

GitHub: https://github.com/deekshith5353
