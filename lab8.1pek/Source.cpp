#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

int CountRecursive(const char* str, int index, bool hasGroups)
{
    // Базовий випадок: досягнуто останнього символу
    if (index >= strlen(str) - 1)
    {
        if (!hasGroups) {
            cout << "Немає груп сусідніх букв." << endl;
        }
        return 0;
    }

    // Перевіряємо, чи утворює поточна пара символів групу
    if ((str[index] == 'a' && str[index + 1] == 'a') ||
        (str[index] == 'b' && str[index + 1] == 'b') ||
        (str[index] == 'c' && str[index + 1] == 'c'))
    {
        hasGroups = true; // Встановлюємо прапорець на true, якщо знайдена група
        return 1 + CountRecursive(str, index + 2, hasGroups); // Рекурсивний виклик збільшуємо лічильник на одиницю
    }

    // Рекурсивний виклик без зміни лічильника та прапорця
    return CountRecursive(str, index + 1, hasGroups);
}

char* Change(const char* str, int index, char* result, int& resultIndex)
{
    // Базовий випадок: досягнуто останнього символу
    if (index >= strlen(str))
    {
        result[resultIndex] = '\0'; // Додаємо завершувальний символ '\0' до зміненого рядка
        return result;
    }

    // Рекурсивний виклик для зміни групи
    if ((str[index] == 'a' && str[index + 1] == 'a') ||
        (str[index] == 'b' && str[index + 1] == 'b') ||
        (str[index] == 'c' && str[index + 1] == 'c'))
    {
        result[resultIndex++] = '*';
        result[resultIndex++] = '*';
        result[resultIndex++] = '*';
        return Change(str, index + 2, result, resultIndex);
    }

    // Рекурсивний виклик без зміни
    result[resultIndex++] = str[index];
    return Change(str, index + 1, result, resultIndex);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_LENGTH = 101;
    char str[MAX_LENGTH];
    cout << "Введіть рядок:" << endl;
    cin.getline(str, MAX_LENGTH);

    int groupCount = CountRecursive(str, 0, false);

    cout << "Рядок містить " << groupCount << " групи 'aa', 'bb' або 'cc'" << endl;
    cout << "Рядок:          " << str << endl;

    char* modifiedStr = new char[MAX_LENGTH * 3 + 1];
    int modifiedStrIndex = 0;
    modifiedStr = Change(str, 0, modifiedStr, modifiedStrIndex);
    cout << "Змінений рядок: " << modifiedStr << endl;

    delete[] modifiedStr;

    return 0;
}