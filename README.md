Student Grade System in C

A terminal-based student management system built in C. Add students, record grades, calculate averages, and backup data.

---

📌 Features

· Add students with 6-digit ID validation
· Enter grades for 5 subjects (0-20 scale)
· Calculate averages automatically
· Search students by ID
· Admin panel: Edit names, grades, delete students
· Backup system: Export data to .txt file

---

🚀 Quick Start
gcc grade_system.c -o grade_system
./grade_system

---

🎮 How to Use🎮

Main Menu:

1. Add Student → Enter ID, name, 5 grades
2. Calculate Averages → Updates all GPAs
3. Search → Find student by ID
4. Admin Panel → Edit/delete/view all
5. Exit

Admin Options:

· Change student name
· Modify grades
· View all students
· Delete student
· Create backup file

---
```
🏗 System Overview
 
┌─────────────────────────────────────────────────────────────┐
│                         MAIN MENU                          │
│                   1.Add | 2.Avg | 3.Search | 4.Admin       │
└─────────────────────────────────────────────────────────────┘
                              │
        ┌─────────────────────┴─────────────────────┐
        │                                           │
        ▼                                           ▼
┌───────────────────┐                     ┌───────────────────┐
│   STUDENT OPS     │                     │    ADMIN OPS      │
├───────────────────┤                     ├───────────────────┤
│ • ADD_STUDENT()   │                     │ • change_name()   │
│ • SEARCH()        │                     │ • change_grade()  │
│ • delete()        │                     │ • info()          │
│ • AVRAGE()        │                     │ • ls()            │
└───────────────────┘                     └───────────────────┘
        │                                           │
        └─────────────────┬─────────────────────────┘
                          ▼
              ┌───────────────────────┐
              │      DATA LAYER       │
              │   struct STUDENT_DATA │
              │   id[20] | name[20]   │
              │   grade[20][5]        │
              │   avrage[20]          │
              └───────────────────────┘
                          │
        ┌─────────────────┴─────────────────┐
        │                                   │
        ▼                                   ▼
┌───────────────────┐               ┌───────────────────┐
│   UTILITIES       │               │    FILE OPS       │
├───────────────────┤               ├───────────────────┤
│ • BUFFER_CLEANER()│               │ • CREATE_BACKUP() │
│ • LOWER_CASE()    │               │                   │
│ • check_pass()    │               │                   │
└───────────────────┘               └───────────────────┘
```

---

🧠 Key Concepts

Concept Implementation
Structs STUDENT_DATA holds all records
Arrays Fixed-size storage for 20 students
File I/O fopen()/fprintf() for backups
Input validation ID format, grade range, duplicate check
String manipulation strcpy(), custom LOWER_CASE()
Buffer cleaning BUFFER_CLEANER() prevents input bugs

---

📁 Data Structure
struct STUDENT_DATA {
    int id[20];          // 6-digit IDs
    char name[20][30];   // Student names  
    float grade[20][5];  // 5 grades each
    float avrage[20];    // Calculated averages
} Data;

---

💡 Purpose

Built to practice:

· C fundamentals (structs, arrays, file handling)
· Input validation and error handling
· CLI application design
· Data persistence

---

🔮 Future Improvements

· Dynamic memory allocation
· Binary file save/load
· Subject names
· Password protection

---

📄 License

MIT

---

[⭐ Star] • [🐛 Report Bug]
