# Address Book Management System

A menu-driven, console-based Address Book application written in C. It allows users to add, view, search, edit, and delete contacts, with contact information stored in a CSV file for persistence between runs.

## Features

- Add a contact with a name, phone number, and email address
- View all saved contacts
- Search for a contact by exact name
- Edit the phone number and email address of an existing contact
- Delete a contact by name
- Load saved contacts when the program starts
- Save contact data to `contacts.csv`

## Technologies and Concepts

- C programming
- Structures and fixed-size arrays
- Functions and modular programming
- Header files
- String handling
- File handling using standard C I/O
- CSV-based data storage
- CRUD operations (Create, Read, Update, Delete)

## Project Structure

```text
Adress-Book/
├── main.c
├── contacts.c
├── contacts.h
└── README.md
```

## Build

Compile the source files with GCC:

```bash
gcc main.c contacts.c -o addressbook
```

On Windows, you can create an executable named `addressbook.exe`:

```powershell
gcc main.c contacts.c -o addressbook.exe
```

## Run

Linux/macOS:

```bash
./addressbook
```

Windows PowerShell:

```powershell
.\addressbook.exe
```

## Menu

When the program starts, it loads contact records from `contacts.csv` in the current working directory (if the file exists), then displays this menu:

```text
1. Add
2. View
3. Search
4. Edit
5. Delete
6. Exit
```

Choose an option and follow the prompts.

## Data Storage

The application stores contacts in a comma-separated file named `contacts.csv`. Each record contains:

```text
name,phone,email
```

Example:

```text
John Doe,9876543210,john@example.com
Jane Smith,9123456789,jane@gmail.com
```

The file is created or rewritten when contacts are saved. Existing records are loaded at startup.

## Implementation Notes

- Contact records are represented by a `struct Contact` containing fixed-size character arrays for the name, phone number, and email.
- The application stores up to 100 contacts in a fixed-size array.
- Contact lookup uses an exact, case-sensitive name match.
- Editing changes the phone number and email address; the name remains unchanged.
- Deleting a contact shifts later array entries to fill the removed position.
- The current CSV read/write implementation expects simple comma-separated fields. Names, phone numbers, and email addresses containing commas are not supported.

## Current Limitations

- The contact array has a fixed capacity of 100 entries.
- Duplicate names are not checked, and name-based search/edit/delete act on the first exact match.
- Phone numbers and email addresses are not validated.
- CSV fields are not escaped, so commas within fields are unsupported.
- The program uses basic console input and does not include a graphical interface.

## Author

Deekshith
