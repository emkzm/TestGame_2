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
    
    Object* obj1 = new Object(10.0, 0, 100, "Object 1", "");
    Object* obj2 = new Object(20.0, 0, 100, "Object 2", "");
    Object* obj3 = new Object(15.3, 0, 100, "Object 3", "");
    Object* obj4 = new Object(12.14, 0, 100, "Object 4", "");
    Object* obj5 = new Object(24.5, 0, 100, "Object 5", "");
    Object* obj6 = new Object(17.86, 0, 100, "Object 6", "");
    Object* obj7 = new Object(13.2, 0, 100, "Object 7", "");
    Object* obj8 = new Object(26.67, 0, 100, "Object 8", "");
    Object* obj9 = new Object(19.41, 0, 100, "Object 9", "");
    Object* obj10 = new Object(18.8, 0, 100, "Object 10", "");
    Object* obj11 = new Object(23.54, 0, 100, "Object 11", "");
    Object* obj12 = new Object(17.63, 0, 100, "Object 12", "");

    std::cout << obj1->get_name() << std::endl;
    std::cout << obj2->get_name() << std::endl;
    std::cout << obj3->get_name() << std::endl;
    std::cout << obj4->get_name() << std::endl;
    std::cout << obj5->get_name() << std::endl;
    std::cout << obj6->get_name() << std::endl;
    std::cout << obj7->get_name() << std::endl;
    std::cout << obj8->get_name() << std::endl;
    std::cout << obj9->get_name() << std::endl;
    std::cout << obj10->get_name() << std::endl;
    std::cout << obj11->get_name() << std::endl;
    std::cout << obj12->get_name() << std::endl;

    Inventory* inv = new Inventory(60.0);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj1);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj2);
    CI->Look_Inventory(inv); 
    system("pause");
    system("cls");
        
    inv->put(obj3);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj4);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj5);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj6);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj7);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj8);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj9);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj10);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj11);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    inv->put(obj12);
    CI->Look_Inventory(inv);
    system("pause");
    system("cls");

    while (true)
    {
        CI->Look_Inventory(inv);
        std::cout << "Какой предмет удалить?" << std::endl;
        int i;
        std::cin >> i;

        inv->smash(i);
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
