
#Group__7


#student name


1. dereje Tesfaye..........................160416
2. Tadios Misganaw.........................161162
3. Biruk Getaye............................160962
4. Bizuye Abebe............................160355
5. Eyerusalem Niguse.......................160528


![image](https://github.com/user-attachments/assets/c00dfce5-ae09-4ca4-a0a1-37db4a398ef6)


# Student__Attendance__System


 A Student Attendance System is used to track and manage the attendance of students in a class.
The system typically allows administrators (or teachers) to record, modify, delete, and 
view attendance records for students.
Classes:

Student Class:
Represents a student with attributes like name, ID, age, and other relevant information.

Attendance Class: Represents a record of a student's attendance, 
usually with attributes like date and status (present/absent).

Vector:
A dynamic array (often used in C++) to store attendance records.
Pointer Usage:
Use pointers to dynamically manage attendance data,
especially when the number of records may change dynamically.

Add Attendance:

Record a student's attendance for a specific date (marking them as present or absent).
Typically involves creating an Attendance object and adding it to a collection (e.g., std::vector).
Example:

void addRecord(Student* student, const string& date, bool present);

Delete Attendance Records:
Remove attendance records based on certain criteria (e.g., student name or date).
Can be done by iterating through the list of attendance records and deleting 
the matching record.
Example:

void deleteRecord(const string& criteria);


Search Attendance:
Search for attendance records by student name or date.
This can be done by iterating through the records and 
comparing the criteria.
Example:

void searchRecord(const string& criteria);
Modify Attendance:
Edit existing attendance records, such as updating a student's
attendance for a specific date.
Example:

void modifyRecord(Student* student, const string& date, bool newStatus);

View All Records:
Display all attendance records for a particular student or for all students in the class.
This can involve iterating through the attendance records and filtering or
displaying them based on certain conditions.
