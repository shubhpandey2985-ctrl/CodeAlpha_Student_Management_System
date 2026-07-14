# 🎓 Student Management System

A **menu-driven Student Management System** developed in **C** as part of the **CodeAlpha C Programming Internship**. The project demonstrates **CRUD (Create, Read, Update, Delete)** operations using **Structures**, **File Handling**, and **Modular Programming**. Student records are stored permanently using binary files, allowing data to persist between program executions.

---

## 📌 Features

- ➕ Add Student
- 📋 Display All Students
- 🔍 Search Student by ID
- ✏️ Update Student Information
- 🗑️ Delete Student Record
- 💾 Persistent Storage using File Handling
- 🧩 Modular Project Structure
- 📑 Menu-Driven Interface
- 🚪 Exit Application

---

# 📋 Main Menu

```text
========================================
     STUDENT MANAGEMENT SYSTEM
========================================
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
========================================
Enter your choice:
```

---

# 📖 Program Flow (Flowchart)

```text
                    START
                      │
                      ▼
           Display Main Menu
                      │
                      ▼
             Read User Choice
                      │
      ┌───────────────┼────────────────┐
      │               │                │
      ▼               ▼                ▼
 Add Student     Display Students   Search Student
      │               │                │
      ├───────────────┼────────────────┤
      ▼               ▼                ▼
 Update Student   Delete Student     Exit
      │               │                │
      └───────────────┼────────────────┘
                      │
                      ▼
             Perform Operation
                      │
                      ▼
             Return to Main Menu
                      │
                 Exit Selected?
                 │          │
                No         Yes
                 │          │
                 └──────────▼
                     END PROGRAM
```

---

# 📂 Project Structure

```text
CodeAlpha_Student_Management_System/
│
├── src/
│   ├── main.c
│   ├── student.c
│   ├── file_handler.c
│   └── utils.c
│
├── include/
│   ├── student.h
│   ├── file_handler.h
│   └── utils.h
│
├── data/
│   └── students.dat
│
├── screenshots/
│   ├── main-menu.png
│   ├── add-student.png
│   ├── display-students.png
│   ├── search-student.png
│   ├── update-student.png
│   └── delete-student.png
│
├── .gitignore
├── LICENSE
├── README.md
└── Makefile (Optional)
```

---

# 🛠 Technologies Used

- C Programming Language
- GCC Compiler
- Standard C Library
- File Handling (Binary Files)

---

# 📚 Concepts Used

- Structures (`struct`)
- Functions
- Header Files
- Modular Programming
- File Handling (`fopen`, `fread`, `fwrite`, `fclose`)
- Binary Files
- Arrays
- Conditional Statements
- Loops
- Input Validation
- Menu-Driven Programming

---

# 🎯 What I Learned

This project helped me understand:

- Designing modular C applications.
- Organizing source and header files.
- Using structures to manage real-world data.
- Implementing CRUD operations.
- Reading from and writing to binary files.
- Searching and updating records efficiently.
- Deleting records using temporary files.
- Improving code readability and maintainability.

---

# 📄 Student Record Format

Each student record contains:

| Field | Type |
|------|------|
| Student ID | Integer |
| Name | Character Array |
| Age | Integer |
| Gender | Character Array |
| Course | Character Array |
| Marks | Float |

---

# 💾 Data Storage

Student records are stored in:

```text
data/students.dat
```

The file is automatically created when the first student record is added.

---

# ⚙️ Requirements

- GCC Compiler
- Windows / Linux / macOS
- Terminal or Command Prompt

---

# 🚀 How to Compile

### Windows / Linux / macOS

```bash
gcc src/*.c -Iinclude -o student_management.exe
```

---

# ▶️ How to Run

### Windows

```bash
student_management.exe
```

or

```bash
.\student_management.exe
```

### Linux / macOS

```bash
./student_management.exe
```

---

# 💻 Sample Workflow

```text
========================================
     STUDENT MANAGEMENT SYSTEM
========================================
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
========================================

Enter your choice: 1

Student ID : 101
Name       : John Doe
Age        : 20
Gender     : Male
Course     : Computer Science
Marks      : 91.5

Student added successfully.
```

---

# ✅ Project Requirements

This project fulfills the following internship requirements:

- ✔ Menu-driven interface
- ✔ Add Student
- ✔ Display Student Records
- ✔ Search Student
- ✔ Update Student Information
- ✔ Delete Student
- ✔ Structures
- ✔ File Handling
- ✔ Modular Programming
- ✔ Persistent Data Storage

---

# 🔮 Future Improvements

- Login & Authentication
- GPA/Grade Calculation
- Student Attendance Management
- Export Records to CSV
- Sorting Student Records
- Advanced Search Filters
- Record Backup & Restore
- Colored Console Output
- Cross-platform Build Support

---

# 📸 Screenshots

Store screenshots in the `screenshots/` folder.

Suggested screenshots:

- Main Menu
- Add Student
- Display Students
- Search Student
- Update Student
- Delete Student

---

# 📜 License

This project is licensed under the **MIT License**.

---

# 👨‍💻 Author

Developed as part of the **CodeAlpha C Programming Internship**.

If you found this project useful, consider giving it a ⭐ on GitHub!
