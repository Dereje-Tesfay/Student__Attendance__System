#include <iostream>
#include <vector>  //add and remove elements
#include <fstream>  //For both reading from and writing to files.
#include <string>
using namespace std;

// Class to represent a student
class Student {
public:
    string name;
    int id;

    Student(string n, int i) : name(n), id(i) {}
    //n=name
    //i=id
};

// Class to manage attendance records
class Attendance {
private:
    struct Record {
        Student* student;
        string date;
        bool present;
    };

    vector<Record*> records; // Vector to dynamically store attendance records

public:
    // Add a new attendance record
    void addRecord(Student* student, const string& date, bool present) {
        records.push_back(new Record{student, date, present});
        cout << "Attendance recorded for " << student->name << " on " << date << ".\n";
    }

    // Delete attendance records by criteria (student name or date)
    void deleteRecord(const string& criteria) {
        auto i = records.begin();
        bool found = false;
        while (i != records.end()) {
            if ((*i)->student->name == criteria || (*i)->date == criteria) {
                delete *i;
                i = records.erase(i);
                found = true;
                cout << "Record deleted.\n";
            } else {
                ++i;
            }
        }
        if (!found) {
            cout << "No matching records found.\n";
        }
    }

    // Search attendance by student name or date
    void search(const string& criteria) {
        bool found = false;
        for (const auto& record : records) {
            if (record->student->name == criteria || record->date == criteria) {
                found = true;
                cout << "Student: " << record->student->name << ", Date: " << record->date
                     << ", Present: " << (record->present ? "Yes" : "No") << "\n";
            }
        }
        if (!found) {
            cout << "No records found for " << criteria << ".\n";
        }
    }

    // Modify attendance record
    void modify(const string& studentName, const string& date, bool newStatus) {
        for (auto& record : records) {
            if (record->student->name == studentName && record->date == date) {
                record->present = newStatus;
                cout << "Attendance updated for " << studentName << " on " << date << ".\n";
                return;
            }
        }
        cout << "Record not found.\n";
    }

    // View all attendance records for a specific student or class
    void viewAll(const string& criteria = "") {
        if (records.empty()) {
            cout << "No attendance records available.\n";
            return;
        }
        for (const auto& record : records) {
            if (criteria.empty() || record->student->name == criteria) {
                cout << "Student: " << record->student->name << ", Date: " << record->date
                     << ", Present: " << (record->present ? "Yes" : "No") << "\n";
            }
        }
    }
    

    // Save attendance data to a file
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& record : records) {
                file << record->student->name << "," << record->student->id << ","
                     << record->date << "," << record->present << "\n";
            }
            file.close();
            cout << "Data saved to " << filename << ".\n";
        } else {
            cout << "Error: Unable to open file for writing.\n";
        }
    }

    // Load attendance data from a file
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            records.clear(); // Clear existing records
            string name, date, presentStr;
            int id;
            while (getline(file, name, ',') && file >>id &&
                   file.ignore() && getline(file, date, ',') && getline(file, presentStr)) {
                records.push_back(new Record{new Student(name, id), date, presentStr == "1"});
            }
            file.close();
            cout << "Data loaded from " << filename << ".\n";
        } else {
            cout << "Error: Unable to open file for reading.\n";
        }
    }

    // Destructor to free dynamically allocated memory
    ~Attendance() {
        for (auto record : records) {
            delete record->student;
            delete record;
        }
    }
};






int main() {
    Attendance attendance;
    vector<Student*> students;

    int choice;
    do {
        cout << " ###Student Attendance System ###"<<endl<<endl;
        cout<<"1. Add Attendance :"<<endl;
        cout<<"2. Delate Attendance :"<<endl;
        cout<<"3. Search Attendance :"<<endl;
        cout<<"4. Modify Attendance :"<<endl;
        cout<<"5. viwe all Attendance :"<<endl;
        cout<< "6. Save to File :"<<endl;
        cout<<"7. Load From File :"<<endl;
        cout<<"8. Exit :"<<endl;
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
        cout<<"Enter your choice: "<<endl;
        cin >> choice;
        
        
        switch (choice) {
        case 1: {
            string name, date;
            int id;
            bool present;
            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter Id Number: ";
            cin >> id;
            cout << "Enter Date (Day/Month/Year): ";
            cin >> date;
            cout << "Present? (1 for Yes, 0 for No): ";
            cin >> present;
            Student* newStudent = new Student(name, id);
            students.push_back(newStudent);
            attendance.addRecord(newStudent, date, present);
            cout << "Attendance record successfully."<<endl;
            break;
        }
        case 2: {
            string criteria;
            cout << "Enter Student Name or Date to delete: ";
            cin >> criteria;
            attendance.deleteRecord(criteria);
            break;
        }
        case 3: {
            string criteria;
            cout << "Enter Student Name or Date to search: ";
            cin >> criteria;
            attendance.search(criteria);
            break;
        }
        case 4: {
            string name, date;
            bool newStatus;
            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter Date (Day/Month/Year): ";
            cin >> date;
            cout << "New Status (1 for Present, 0 for Absent): ";
            cin >> newStatus;
            attendance.modify(name, date, newStatus);
            break;
        }
        case 5: {
           attendance.viewAll();  // View all attendance records for the class
            break;
        }
        case 6: {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            attendance.saveToFile(filename);
            break;
        }
        case 7: {
            string filename;
            cout << "Enter filename to load: ";
            cin >> filename;
            attendance.loadFromFile(filename);
            break;
        }
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    for (auto student : students) {
        delete student;
    }

    return 0;
}
