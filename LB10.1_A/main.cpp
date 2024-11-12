#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>


using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "Інформатика ",
                            "Радіоелектроніка", "Комп'ютерні науки",
                            "Комп'ютерна інженерія", "Програмне забезпечення" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_info;

};

void Create(Students* S, const int N);
void count_good_grades(Students* S, int N, int& count_math, int& count_physics, int& count_info);
double Percentage(Students* S, const int N);
void Print(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    int count_math = 0;
    int count_physics = 0;
    int count_info = 0;

    count_good_grades(S, N, count_math, count_physics, count_info);

    cout << "Кількість оцінок 'добре' з математики: " << count_math << endl;
    cout << "Кількість оцінок 'добре' з фізики: " << count_physics << endl;
    cout << "Кількість оцінок 'добре' з інформатики: " << count_info << endl;

    cout << "Процент студентів, які отримали 5 і з фізики і з математики: " << setprecision(2) << Percentage(S, N) << "%";

    return 0;
}


void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Номер студента: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище: "; getline(cin, S[i].surname); cout << endl;
        cout << "Курс: "; cin >> S[i].course; cout << endl;
        cout << "Спеціальність(0 - Інформатика, 1 - Радіоелектроніка, 2 - Комп'ютерні науки,";
        cout << "\n3 - Комп'ютерна інженерія, 4 - Програмне забезпечення): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "Оцінка з фізики: "; cin >> S[i].grade_physics; cout << endl;
        cout << "Оцінка з математики: "; cin >> S[i].grade_math; cout << endl;
        cout << "Оцінка з інформатики: "; cin >> S[i].grade_info; cout << endl;
        cout << endl;
    }
}

void count_good_grades(Students* S, int N, int& count_math, int& count_physics, int& count_info)
{
    count_math = 0;
    count_physics = 0;
    count_info = 0;

    for (int i = 0; i < N; i++) {
        if (S[i].grade_math == 4) {
            count_math++;
        }
        if (S[i].grade_physics == 4) {
            count_physics++;
        }
        if (S[i].grade_info == 4) {
            count_info++;
        }
    }
}


void Print(Students* S, const int N)
{
    cout << "=================================================================================================" << endl;
    cout << "|  №  |   Прізвище   |  Курс  |     Спеціальність     |  Фізика  |  Математика  |  Інформатика  |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << left << i + 1 << " ";
        cout << "|" << setw(14) << left << S[i].surname;
        cout << "|" << setw(8) << left << S[i].course;
        cout << "|" << setw(23) << left << speciality_str[S[i].speciality];
        cout << "|" << setw(10) << left << S[i].grade_physics;
        cout << "|" << setw(14) << left << S[i].grade_math;
        cout << "|" << setw(15) << left << S[i].grade_info << "|" << endl;
    }
    cout << "=================================================================================================" << endl << endl;
}

double Percentage(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics == 5 && S[i].grade_math == 5)
            k++;
    return k * 1. / (N) * 100;
}
