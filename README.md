# Hospital Management System 

This is a console based application I built to understand the basics of **File Handling** in C++. Instead of using a complex database, this project uses text files to store patient records permanently.

It was a great way for me to learn how to Create, Read, Update, and Delete (CRUD) data using standard C++ libraries.

### Key Features
* **Add Records:** Save new patient details (ID, Name, Age, Disease).
* **View & Search:** Display all patients or find a specific one by their ID.
* **Edit & Delete:** Update patient information or remove records from the file.
* **Data Persistence:** All data is saved in a text file, so it doesn't disappear when the program closes.

### How It Works
The program runs on a simple menu loop. When you modify a record (like editing or deleting), the code uses temporary files to handle the changes safely before updating the main record file.

### Tools Used
* Language: **C++**
* Core Concept: **File Handling** (`fstream`, `ifstream`, `ofstream`)
* Logic: Loops and Functions

### How to Run
1.  Download the source code file.
2.  Open it in any C++ IDE (like Visual Studio, DevC++, or Code::Blocks).
3.  Compile and run.

### Future Improvements
I plan to eventually add password protection for the admin and maybe create a simple graphical interface (GUI) for it later on.
