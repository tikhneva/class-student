#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string surname;
    string father_name;
    string birth_date;
    string home_address;
    string phone_number;
    int age;

    int* practice_grades = nullptr;
    int practice_grades_count = 0;

    int* hometask_grades = nullptr;
    int hometask_grades_count = 0;

    int* exam_grades = nullptr;
    int exam_grades_count = 0;
    

public:
    Student() : name(""), surname(""), father_name(""), birth_date(""), home_address(""), phone_number("") {
        cout << "Student has been created!" << endl;
    }

    Student(string name, string surname, string father_name, string birth_date, string home_address, string phone_number)
        : name(name), surname(surname), father_name(father_name), birth_date(birth_date), home_address(home_address), phone_number(phone_number) {}

    ~Student()
    {
        if (practice_grades != nullptr)
        {
            delete[] practice_grades;
            practice_grades = nullptr;
        }
        if (hometask_grades != nullptr)
        {
            delete[] hometask_grades;
            hometask_grades = nullptr;
        }
        if (exam_grades != nullptr)
        {
            delete[] exam_grades;
            exam_grades = nullptr;
        }
    }

    void SetName(string name)
    {
        this->name = name;
    }

    string GetName() const
    {
        return name;
    }

    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    string GetSurname() const
    {
        return surname;
    }

    void SetFatherName(string father_name) {
        this->father_name = father_name;
    }

    string GetFatherName() const {
        return father_name;
    }

    void SetBirthDate(string birth_date) {
        this->birth_date = birth_date;
    }

    string GetBirthDate() const {
        return birth_date;
    }

    void SetAddress(string home_address) {
        this->home_address = home_address;
    }

    string GetAddress() const {
        return home_address;
    }

    void SetPhoneNumber(string phone_number) {
        this->phone_number = phone_number;
    }

    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    int GetAge() const
    {
        return age;
    }

    void AddPracticeGrade(unsigned int grade)
    {
        if (grade < 1 || grade > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (practice_grades_count == 0)
        {
            practice_grades = new int[1];
            practice_grades[0] = grade;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[practice_grades_count + 1];

            for (int i = 0; i < practice_grades_count; i++)
            {
                temp[i] = practice_grades[i];
            }
            temp[practice_grades_count] = grade;

            delete[] practice_grades;

            practice_grades = temp;
        }

        practice_grades_count++;
    }

    int GetPracticeGradesCount() const
    {
        return practice_grades_count;
    }
    int* GetPracticeGrades() const
    {
        return practice_grades;
    }

    void AddHometaskGrade(unsigned int grade)
    {
        if (grade < 1 || grade > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_grades_count == 0)
        {
            hometask_grades = new int[1];
            hometask_grades[0] = grade;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[hometask_grades_count + 1];

            for (int i = 0; i < hometask_grades_count; i++)
            {
                temp[i] = hometask_grades[i];
            }
            temp[hometask_grades_count] = grade;

            delete[] hometask_grades;

            hometask_grades = temp;
        }

        hometask_grades_count++;
    }

    int GetHometasksGradesCount() const
    {
        return hometask_grades_count;
    }
    int* GetHometaskGrades() const
    {
        return hometask_grades;
    }

    void AddExamGrade(unsigned int grade)
    {
        if (grade < 1 || grade > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (exam_grades_count == 0)
        {
            exam_grades = new int[1];
            exam_grades[0] = grade;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[exam_grades_count + 1];

            for (int i = 0; i < exam_grades_count; i++)
            {
                temp[i] = exam_grades[i];
            }
            temp[exam_grades_count] = grade;

            delete[] exam_grades;

            exam_grades = temp;
        }

        exam_grades_count++;
    }

    int GetExamGradesCount() const
    {
        return hometask_grades_count;
    }
    int* GetExamGrades() const
    {
        return exam_grades;
    }

    void ShowStudent() const {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Father Name: " << father_name << endl;
        cout << "Birth Date: " << birth_date << endl;
        cout << "Home Address: " << home_address << endl;
        cout << "Phone Number: " << phone_number << endl;

        cout << "Practice Grades: ";
        for (int i = 0; i < practice_grades_count; ++i) {
            cout << practice_grades[i] << " " << endl;
        }

        cout << "Hometask Grades: ";
        for (int i = 0; i < hometask_grades_count; ++i) {
            cout << hometask_grades[i] << " " << endl;
        }

        cout << "Exam Grades: ";
        for (int i = 0; i < exam_grades_count; ++i) {
            cout << exam_grades[i] << " " << endl;
        }

    }

};

int main()
{
    Student s;

    s.SetName("Jisung");
    s.SetSurname("Han");
    s.SetFatherName("JOne");
    s.SetBirthDate("2000.09.14");
    s.SetAddress("Cheongpa-ro 43-gil");
    s.SetPhoneNumber("+82-10-7498-7345");
    s.AddPracticeGrade(12);
    s.AddHometaskGrade(11);
    s.AddExamGrade(10);

    s.ShowStudent();
};
