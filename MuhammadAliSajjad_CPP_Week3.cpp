#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student
{
protected:
    char *grade; // Dynamic arrays for storing multiple student's information
    int *marks;
    long long *student_ID;
    char **name;
    int numstudents;

public:
    Student() // Default constructor to initialize member pointers to NULL
    {
        grade = NULL;
        numstudents = 0;
        marks = NULL;
        student_ID = NULL;
        name = NULL;
    }
    // Parameterized constructor to initialize arrays based on number of students
    Student(int numstud)

    {
        grade = new char[numstud];
        numstudents = numstud;
        name = new char *[numstud];

        for (int i = 0; i < numstud; i++)
            name[i] = new char[100];
        student_ID = new long long[numstud];
        marks = new int[numstud];
    }
    Student(char **n, int *id, int *m, int numstud)
    {
        numstudents = numstud;

        grade = new char[numstud];
        name = new char *[numstud];
        for (int i = 0; i < numstud; i++)
            name[i] = new char[100];
        student_ID = new long long[numstud];
        marks = new int[numstud];
        for (int i = 0; i < numstud; i++)
        {
            marks[i] = m[i];
            student_ID[i] = id[i];
            copyString(name[i], n[i]);
        }
    }
    // Copy constructor to deeply copy student details from another object
    Student(const Student &c)

    {
        this->numstudents = c.numstudents;
        name = new char *[numstudents];
        for (int i = 0; i < numstudents; i++)
            name[i] = new char[100];
        student_ID = new long long[numstudents];
        marks = new int[numstudents];
        grade = new char[numstudents];
        for (int i = 0; i < numstudents; i++)
        {
            this->marks[i] = c.marks[i];
            this->student_ID[i] = c.student_ID[i];
            copyString(this->name[i], c.name[i]);
            this->grade[i] = c.grade[i];
        }
    }
    int lengthofID(int num) // Function for finding length of digits in number ID
    {
        int count = 0;
        while (num != 0)
        {
            count++;
            num /= 10;
        }
        return count;
    }
    int Length(char *str) // Function to calculate length of character array
    {
        int l = 0;
        char ch = str[0];
        while (str[l] != '\0')
        {
            l++;
        }
        return l;
    }
    void copyString(char *str1, const char *str2) // Function to copy character by character one array to another
    {
        int i;
        for (i = 0; str2[i] != '\0'; i++)
        {
            str1[i] = str2[i];
        }
        str1[i] = '\0';
    }
    // Inputs student name, ID and marks with basic validation
    void Input(int numstudents)

    {

        for (int i = 0; i < numstudents; i++)
        {
            cout << "\nEnter student " << i + 1 << " name: ";
            cin.ignore(); // Ignore space
            cin.getline(name[i], 100);
            while (Length(name[i]) >= 20 || Length(name[i]) == 0) // Validate name length
            {

                cout << "\nInvalid, current length of name is: " << Length(name[i]) << "\nName is either missing or too long. ";
                cout << "\nEnter student " << i + 1 << " name (upto 20 characters): ";

                cin.getline(name[i], 20);
            }

            cout << "Enter student " << i + 1 << " ID (9 digits max):";
            cin >> student_ID[i];
            while (lengthofID(student_ID[i]) >= 10) // Validate Number of digits in ID
            {
                cout << "\nInvalid. ID length is out of range.\nEnter student " << i + 1 << " ID (1-10 numbers):";
                cin >> student_ID[i];
            }
            cout << "Enter student " << i + 1 << " marks:";
            cin >> marks[i];
            while (marks[i] < 0 || marks[i] > 100) // Validate marks entered
            {
                cout << "\nInvalid.\nEnter student " << i + 1 << " marks:";
                cin >> marks[i];
            }
            grade[i] = calculate_grade(i); // Get Grades
        }
    }

    // Getters
    int getMarks(int index)
    {
        return marks[index];
    }
    char *getStudentName(int index)
    {
        return name[index];
    }
    int getStudentID(int index)
    {
        return student_ID[index];
    }
    int getStudentMarks(int index)
    {
        return marks[index];
    }
    void setGrade(char g, int i)
    {
        grade[i] = g;
    }
    // Assign grade based on marks using standard grading scheme
    char calculate_grade(int index)

    {
        char g;
        if (getMarks(index) >= 90 && getMarks(index) <= 100)
            g = 'A';
        else if (getMarks(index) >= 80 && getMarks(index) < 90)
            g = 'B';
        else if (getMarks(index) >= 70 && getMarks(index) < 80)
            g = 'C';

        else if (getMarks(index) >= 60 && getMarks(index) < 70)
            g = 'D';

        else if (getMarks(index) >= 50 && getMarks(index) < 60)
            g = 'E';

        else
            g = 'F';

        setGrade(g, index); // Set grades
        return g;
    }

    // Displays all student records in a formatted table, with polymorphism only for display function
    virtual void display()

    {
        cout << "\n\t----------Student details----------" << endl;
        cout << "\nStudent name: " << "\tStudent ID: " << "\tStudent grade: " << "\tStudent Marks: " << endl;

        for (int i = 0; i < numstudents; i++)
        {
            cout << right << setw(13) << name[i] << right << setw(14) << student_ID[i] << right << setw(15) << grade[i] << right << setw(15) << marks[i] << endl;
        }
    }
    int getNumStudents()
    {
        return numstudents;
    }
    // Destructor to deallocate dynamically allocated memory
    ~Student()

    {
        if (name)
        {
            for (int i = 0; i < numstudents; i++)
            {
                if (name[i])
                    delete[] name[i];
            }
            delete[] name;
        }
        if (student_ID)
            delete[] student_ID;
        if (marks)
            delete[] marks;
        if (grade)
            delete[] grade;
    }
};
class Contact : public Student // Contact class to collect student ID
{
private:
    int *ID;

public:
    Contact() : Student() {}               // Default constructor
    Contact(const Student &c) : Student(c) // Parametrized constructor to copy all attributes of Student from main inside Contact to Student
    {
        ID = new int[getNumStudents()];
        for (int i = 0; i < getNumStudents(); i++)
            this->ID[i] = getStudentID(i);
    }
    void display() override // Calling same display function but int different way
    {
        cout << "\n\t----------Contact details----------" << endl;
        cout << "\nStudent name: " << "\tStudent ID: " << endl;

        for (int i = 0; i < numstudents; i++)
        {
            cout << right << setw(13) << name[i] << right << setw(14) << student_ID[i] << endl;
        }
    }
    bool searchID(int id)
    {
        for (int i = 0; i < numstudents; i++)
        {
            if (getStudentID(i) == id)
            {
                return true;
            }
        }
        return false;
    }

    void ReadFile(const char *file)
    {
        ifstream fs(file);
        if (!fs)
        {
            cout << "\nError, cannot open file";
            fs.close();
            return;
        }
        char *ch = new char[100];
        while (fs.getline(ch, 100))
        {
            cout << ch << endl;
        }
        delete[] ch;
        fs.close();
    }
    void WriteFile(const char *file)
    {
        ofstream fs(file);
        if (!fs)
        {
            cout << "\nError, cannot open file";
            fs.close();
            return;
        }
        if (fs.is_open())
        {
            fs << "\n\t----------Contact details----------" << endl;
            fs << "\nStudent name: " << "\tStudent ID: " << endl;

            for (int i = 0; i < numstudents; i++)
            {
                fs << right << setw(13) << name[i] << ",";
                fs << right << setw(13) << student_ID[i];
                fs << right << setw(13) << endl;
            }
        }
        fs.close();
    }
    ~Contact() // Destructor to free memory
    {
        if (ID)
            delete[] ID;
    }
};

class Graduate : public Student // Graduate class to determine student eligibility
{
private:
    bool *eligibility;

public:
    Graduate() // Default Constructor
    {
        eligibility = NULL;
    }
    // Constructor to initialize eligibility array
    Graduate(const Student &student)
        : Student(student) // Parametrized constructor to copy all attributes of Student from main inside Contact to Student

    {

        eligibility = new bool[numstudents];
        for (int i = 0; i < numstudents; i++)
        {
            eligibility[i] = 0;
        }
    }
    // Determines graduation eligibility (grade should not be F)
    bool checkEligibility(int index) // Function to calculate Eligibility using getter from Student class

    {
        if (calculate_grade(index) != 'F')
        {
            eligibility[index] = true;
            return true;
        }
        else
            return false;
    }

    void ReadFile(const char *file)
    // Reads and displays file contents
    {
        ifstream fs(file);
        if (!fs)
        {
            cout << "\nError, cannot open file";
            fs.close();
            return;
        }
        char *ch = new char[100];
        while (fs.getline(ch, 100))
        {
            cout << ch << endl;
        }
        delete[] ch;
        fs.close();
    }
    void WriteFile(const char *file) // Writes contact info to a file in readable format
    {
        ofstream fs(file);
        if (!fs)
        {
            cout << "\nError, cannot open file";
            fs.close();
            return;
        }
        if (fs.is_open())
        {
            fs << "\n\t----------Student details----------" << endl;
            fs << "\nStudent name: " << "\tStudent ID: " << "\tStudent grade: " << "\tStudent Marks: " << endl;

            for (int i = 0; i < getNumStudents(); i++)
            {
                fs << right << setw(13) << name[i] << ",";
                fs << right << setw(13) << student_ID[i] << ",";
                fs << right << setw(13) << marks[i] << ",";
                fs << right << setw(13) << ((checkEligibility(i) ? "Eligible" : "Not eligible")) << endl;
                cout << endl;
            }
        }
        fs.close();
    }
    void AppendFile(const char *file)
    {
        ofstream fs(file, ios::app);
        if (!fs)
        {
            cout << "\nError, cannot open file";
            fs.close();
            return;
        }
        if (fs.is_open())
        {

            for (int i = 0; i < getNumStudents(); i++)
            {
                fs << right << setw(13) << name[i] << ",";
                fs << right << setw(13) << student_ID[i] << ",";
                fs << right << setw(13) << marks[i] << ",";
                fs << right << setw(13) << ((checkEligibility(i) ? "Eligible" : "Not eligible")) << endl;
                cout << endl;
            }
        }
        fs.close();
    }

    // Displays student info along with graduation eligibility
    void display() override

    {
        Student::display();
        for (int i = 0; i < getNumStudents(); i++)
            cout << "\nEligibility status for student " << i << " to graduate: " << (checkEligibility(i) ? "Eligible" : "Ineligible");
    }
    ~Graduate() // destructor to free memory
    {
        if (eligibility)
            delete[] eligibility;
    }
};
// Main function to drive the student record system

int main()
{

    int choice;
    bool menu = true;
    while (menu) // Main menu loop to interact with the user

    {
        cout << "\n\n\tWelcome to Student Record Management System.\n\nDo you want to:\n1. Write to an empty file and Obtain Student Contact info by entering student ID.\n2. Read contents from the file database.\n3. Append new info to end of file database.\n4. Show all contacts.\n5. Exit \nPlease enter your choice: ";
        cin >> choice;
        if (choice == 1) // Option 1: Input student data, write to file, and allow ID search

        {
            int numstudents;
            cout << "\nEnter number of students: ";
            cin >> numstudents;
            Student student(numstudents);
            student.Input(numstudents);

            Graduate grad(student);
            grad.display();
            grad.WriteFile("student.txt");

            Contact contact(student);
            contact.WriteFile("Contact.txt");
            contact.display();
            cout << "\nDone";

            int id;
            cout << "\nEnter ID to search: ";
            cin >> id;
            if (contact.searchID(id))
            {
                cout << "\nFound " << id;
            }
            else
            {
                cout << "\nNot found";
            }
        }
        else if (choice == 2) // Option 2: Read and display contents of student file

        {
            cout << "\nReading file contents......." << endl
                 << endl;

            Graduate g;
            g.ReadFile("student.txt");
        }
        else if (choice == 3) // Option 3: Append new student records to the existing file

        {
            int numstudents;
            cout << "\nEnter number of students: ";
            cin >> numstudents;
            Student s(numstudents);
            s.Input(numstudents);
            Graduate g(s);
            g.AppendFile("student.txt");

            Contact contact(s);
            contact.WriteFile("Contact.txt");
            cout << "\nDone";
        }

        else if (choice == 4) // Option 4: Display contact information from file

        {
            Contact c;

            c.ReadFile("Contact.txt");
        }
        else if (choice == 5) // Option 5: Exit the program

        {
            menu = false;
        }

        else // Invalid choice entered by user

        {
            cout << "\nInvalid choice";
        }
    }

    return 0;
}
