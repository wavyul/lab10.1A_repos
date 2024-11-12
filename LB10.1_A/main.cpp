#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>


using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "����������� ",
                            "��������������", "����'����� �����",
                            "����'������ ��������", "��������� ������������" };

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
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    int count_math = 0;
    int count_physics = 0;
    int count_info = 0;

    count_good_grades(S, N, count_math, count_physics, count_info);

    cout << "ʳ������ ������ '�����' � ����������: " << count_math << endl;
    cout << "ʳ������ ������ '�����' � ������: " << count_physics << endl;
    cout << "ʳ������ ������ '�����' � �����������: " << count_info << endl;

    cout << "������� ��������, �� �������� 5 � � ������ � � ����������: " << setprecision(2) << Percentage(S, N) << "%";

    return 0;
}


void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "�������: "; getline(cin, S[i].surname); cout << endl;
        cout << "����: "; cin >> S[i].course; cout << endl;
        cout << "������������(0 - �����������, 1 - ��������������, 2 - ����'����� �����,";
        cout << "\n3 - ����'������ ��������, 4 - ��������� ������������): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "������ � ������: "; cin >> S[i].grade_physics; cout << endl;
        cout << "������ � ����������: "; cin >> S[i].grade_math; cout << endl;
        cout << "������ � �����������: "; cin >> S[i].grade_info; cout << endl;
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
    cout << "|  �  |   �������   |  ����  |     ������������     |  Գ����  |  ����������  |  �����������  |" << endl;
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
