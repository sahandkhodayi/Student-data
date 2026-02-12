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

🏗 System Architecture
┌─────────────────────────────────────────────────────────────┐
│                         MAIN MENU                          │
│                    (ADD | AVERAGE | SEARCH | ADMIN)        │
└─────────────────┬───────────────────────────────────────────┘
                  │
    ┌─────────────┴─────────────┬──────────────┬──────────────┐
    │                           │              │              │
    ▼                           ▼              ▼              ▼
┌─────────┐              ┌─────────┐    ┌─────────┐    ┌─────────┐
│  ADD    │              │AVERAGE  │    │ SEARCH  │    │ ADMIN   │
│STUDENT  │              │CALCULATOR│   │  BY ID  │    │ PANEL   │
└────┬────┘              └────┬────┘    └────┬────┘    └────┬────┘
     │                         │              │              │
     └─────────────────────────┴──────────────┴──────────────┘
                              │
                              ▼
                    ┌─────────────────┐
                    │   DATA LAYER    │
                    │  struct Data    │
                    │  id[20]         │
                    │  name[20][30]   │
                    │  grade[20][5]   │
                    │  avrage[20]     │
                    └────────┬────────┘
                             │
              ┌──────────────┴──────────────┐
              │                             │
              ▼                             ▼
      ┌───────────────┐             ┌───────────────┐
      │   BACKUP      │             │   DISPLAY     │
      │   TO FILE     │             │   TO TERMINAL │
      └───────────────┘             └───────────────┘

Data Flow
User Input → Validation → Data Store ←→ Computation ←→ Output
      ↑           ↓            ↑              ↓
      └───────────┴────────────┴──────────────┘
                    Buffer Cleaner
              (Prevents input overflow bugs)

Module Dependencies
┌─────────────────────────────────────────────────┐
│                    main()                       │
│  Loop: Display menu → Get choice → Switch      │
└─────────────────────────────────────────────────┘
                          │
        ┌─────────────────┼─────────────────┐
        ▼                 ▼                 ▼
┌───────────────┐ ┌───────────────┐ ┌───────────────┐
│  Student Ops  │ │  Grade Ops    │ │   Admin Ops   │
│  ADD_STUDENT  │ │  AVRAGE       │ │  change_name  │
│  SEARCH       │ │  grades_LIST  │ │  change_grade │
│  delete       │ │  grades       │ │  info         │
│               │ │  check_pass   │ │  ls           │
└───────────────┘ └───────────────┘ └───────────────┘
        │                 │                 │
        └─────────────────┼─────────────────┘
                          ▼
              ┌─────────────────────┐
              │   Utility Layer     │
              │  BUFFER_CLEANER     │
              │  LOWER_CASE         │
              │  CREATE_BACKUP      │
              └─────────────────────┘

---

🚀 Quick Start
gcc grade_system.c -o grade_system
./grade_system

---

🎮 How to Use

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

🧠 Key Concepts Demonstrated

Concept Implementation
Structs STUDENT_DATA holds all records
Arrays Fixed-size storage for 20 students
File I/O fopen()/fprintf() for backups
Input validation ID format, grade range, duplicate check
String manipulation strcpy(), custom LOWER_CASE()
Buffer cleaning BUFFER_CLEANER() prevents input bugs
Recursion SEARCH() calls itself for retry
Pointer arithmetic String case conversion

---

📁 Data Structure
struct STUDENT_DATA {
    int id[20];          // 6-digit IDs
    char name[20][30];   // Student names  
    float grade[20][5];  // 5 grades each
    float avrage[20];    // Calculated averages
} Data;

---

💡 Why This Project?

Built to practice:

· C fundamentals (structs, arrays, file handling)
· Real-world input validation
· CLI application design
· Data persistence without databases
· Buffer overflow prevention

---

🔮 Future Improvements

· Dynamic memory allocation (remove student limit)
· Binary file save/load
· Subject names instead of numbers
· GUI version with ncurses
· Password protection for admin panel

---

📄 License

MIT

---

Built with: C standard library only — no external dependencies.

[⭐ Star on GitHub] • [🐛 Report Bug] • [📬 Contact]
