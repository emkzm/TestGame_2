// TestGame_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Object.h"
#include "Inventory.h"
#include "ConsoleInterface.h"

int main()
{
    setlocale(0, "rus");
    ConsoleInterface* CI = new ConsoleInterface();
    
    Object* obj[] = { 
        new Object(10.0, 0, 100, "Bread", ""),
        new Object(20.0, 0, 100, "Kolbasa", ""),
        new Object(15.3, 0, 100, "Sosiska", ""),
        new Object(12.14, 0, 100, "Salamy", ""),
        new Object(24.5, 0, 100, "Alisa", "")
    };
    
    Inventory* inv = new Inventory(60.0);
    CI->LookInventory(inv);
    system("pause");
    system("cls");

    for (int i = 0; i < 5; i++)
    {
        inv->put(obj[i]);
        CI->LookInventory(inv);
        system("pause");
        system("cls");
    }
    
    while (true)
    {
        CI->SelectionToDeleteMenu(inv);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
