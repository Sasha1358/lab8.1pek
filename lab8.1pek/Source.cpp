#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

int CountRecursive(const char* str, int index, bool hasGroups)
{
    // ������� �������: ��������� ���������� �������
    if (index >= strlen(str) - 1)
    {
        if (!hasGroups) {
            cout << "���� ���� ������ ����." << endl;
        }
        return 0;
    }

    // ����������, �� ������� ������� ���� ������� �����
    if ((str[index] == 'a' && str[index + 1] == 'a') ||
        (str[index] == 'b' && str[index + 1] == 'b') ||
        (str[index] == 'c' && str[index + 1] == 'c'))
    {
        hasGroups = true; // ������������ ��������� �� true, ���� �������� �����
        return 1 + CountRecursive(str, index + 2, hasGroups); // ����������� ������ �������� �������� �� �������
    }

    // ����������� ������ ��� ���� ��������� �� ��������
    return CountRecursive(str, index + 1, hasGroups);
}

char* Change(const char* str, int index, char* result, int& resultIndex)
{
    // ������� �������: ��������� ���������� �������
    if (index >= strlen(str))
    {
        result[resultIndex] = '\0'; // ������ �������������� ������ '\0' �� �������� �����
        return result;
    }

    // ����������� ������ ��� ���� �����
    if ((str[index] == 'a' && str[index + 1] == 'a') ||
        (str[index] == 'b' && str[index + 1] == 'b') ||
        (str[index] == 'c' && str[index + 1] == 'c'))
    {
        result[resultIndex++] = '*';
        result[resultIndex++] = '*';
        result[resultIndex++] = '*';
        return Change(str, index + 2, result, resultIndex);
    }

    // ����������� ������ ��� ����
    result[resultIndex++] = str[index];
    return Change(str, index + 1, result, resultIndex);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_LENGTH = 101;
    char str[MAX_LENGTH];
    cout << "������ �����:" << endl;
    cin.getline(str, MAX_LENGTH);

    int groupCount = CountRecursive(str, 0, false);

    cout << "����� ������ " << groupCount << " ����� 'aa', 'bb' ��� 'cc'" << endl;
    cout << "�����:          " << str << endl;

    char* modifiedStr = new char[MAX_LENGTH * 3 + 1];
    int modifiedStrIndex = 0;
    modifiedStr = Change(str, 0, modifiedStr, modifiedStrIndex);
    cout << "������� �����: " << modifiedStr << endl;

    delete[] modifiedStr;

    return 0;
}