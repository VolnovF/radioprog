#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name{};
    int mark{};
};

using students_t = std::vector<Student>;

// Ввод колличества студентов
// Проверяет что их более 0
size_t numberOfStudents()
{
    size_t numberOfStudents{0};
    do
    {
        std::cout << "How many students do you need to enter? : ";
        std::cin >> numberOfStudents;
    } while (numberOfStudents <= 0);

    return numberOfStudents;
}

// Ввод данных каждого студента 
// Оценка может быть только от 0 до 100
void enterStudent(Student& student)
{
    std::cout << "Enter student name: ";
    std::getline(std::cin >> std::ws, student.name);

    int mark{};
    do
    {
        std::cout << "Enter student mark: ";
        std::cin >> mark;
    } while ((mark < 0) || (mark > 100));
    
    student.mark = mark;
}
void enterAllStudents(students_t& students)
{
    std::for_each(students.begin(), students.end(), enterStudent);
}

// Сортировка студенов по оценке
bool greaterStudent(Student& a, Student& b)
{
    return (a.mark > b.mark);
}
void sortAllStudents(students_t& students)
{
    std::sort(students.begin(), students.end(), greaterStudent);
}

// Вывод данных о студентах
void printStudent(const Student& student)
{
    std::cout << student.name << " got a grade of " << student.mark << '\n';
}
void printAllStudents(const students_t& students)
{
   std::for_each(students.begin(), students.end(), printStudent);
}

int main()
{
    students_t students(numberOfStudents());
    enterAllStudents(students);
    sortAllStudents(students);
    printAllStudents(students);

    return 0;
}