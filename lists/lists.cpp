// lists.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SinglyLincked.h"
#include "DoubleLinckedList.h"

void TestList()
{
    auto l = new DoubleLinckedList<int>();

    l->Add(0);
    l->Print();

    l->Add(1);
    l->Print();

    l->Add(2);
    l->Print();

    l->Add(3);
    l->Print();

    cout << "Test GetElementAt(i)" << endl;
    for (size_t i = 0; i < l->GetCount(); i++)
    {
        cout << l->GetElementAt(i) << '\t';
    }
    cout << endl;

    cout << "Test SetElementAt(i)" << endl;
    for (size_t i = 0; i < l->GetCount(); i++)
    {
        l->SetElementAt(i, rand());
        cout << l->GetElementAt(i) << '\t';
    }
    cout << endl;


    l->Remove(41);
    l->Print();

    l->Remove(18467);
    l->Print();

    l->Remove(3);
    l->Print();

    l->Remove(0);
    l->Print();
}

bool ElementIn(int element, SinglyLincked<int>*lst)
{
    for (size_t i = 0; i < lst->GetCount(); i++)
    {
        if (element == lst->GetElementAt(i))
        {
            return true;
        }
    }
    return false;
}

void Var8()
{
    auto l1 = new SinglyLincked<int>(), 
        l2 = new SinglyLincked<int>(),
        res = new SinglyLincked<int>();

    l1->Add(0);
    l1->Add(1);
    l1->Add(5);
    l1->Add(2);
    l1->Add(3);

    l2->Add(0);
    l2->Add(0);
    l2->Add(3);
    l2->Add(4);
    l2->Add(1);
    l2->Add(2);

    for (size_t i = 0; i < l1->GetCount(); i++)
    {
        auto el = l1->GetElementAt(i);
        if ((! ElementIn(el, l2)) && 
            (!ElementIn(el, res)))
        {
            res->Add(el);
        }
    }
    for (size_t i = 0; i < l2->GetCount(); i++)
    {
        auto el = l2->GetElementAt(i);
        if ((!ElementIn(el, l1)) &&
            (!ElementIn(el, res)))
        {
            res->Add(el);
        }
    }

    res->Print();
}
int main()
{
    Var8();
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
