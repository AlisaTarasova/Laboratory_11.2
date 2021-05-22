#include <iostream>
#include<stack>
using namespace std;
stack<char>Stack2;
stack<char>StackSTL;

struct Stack1
{
	char info;
	Stack1* prev;
};

Stack1* Vvod1(int n1)
{
	Stack1* top, *a;
	top = NULL;
	a = new Stack1;
	cout << "Введите " << n1 << " элемент стека: ";
	cin >> a->info;
	a->prev=NULL;
	top = a;
	for (int i = 2; i <= n1; i++)
	{
		Stack1*b = new Stack1;
		cout << "Введите " <<n1- i+1<< " элемент стека: ";
		cin >> b->info;
		b->prev = top;
		top = b;
	}
	return top;
}

void Print1(Stack1*top)
{
	Stack1* a = top;
	while (a != NULL)
	{
		cout << a->info << "\t";
		a=a->prev;
	}
	cout << endl;
}

void Adding1(Stack1* top,char set_info)
{
	Stack1* key = NULL;
	Stack1* key_prev = NULL;
	while (top!= NULL)
	{
		if (top->info == set_info)
		{
			key = top;
			key_prev = top->prev;
		}
		top = top->prev;
	}
	if (key != NULL)
	{
		Stack1* a = new Stack1;
		cout << "Введите элемент, который надо добавить в стек: ";
		cin >> a->info;
		key->prev = a;
		a->prev = key_prev;
	}
}

///////////////////////////////////////////////////////////////////////

void Vvod2(int n2)
{
	char a;
	for (int i = 1; i <= n2; i++)
	{
		cout << "Введите " << i << " элемент стека: ";
		cin >> a;
		Stack2.push(a);
	}
}

void Print2(int n2)
{
	for (int i = 1; i <= n2; i++)
	{
		cout << Stack2.top()<<"\t";
		StackSTL.push(Stack2.top());
		Stack2.pop();
	}
	cout << endl;
}

void Adding2(char set_info2, int n2)
{
	char a;
	while (StackSTL.empty() != true)
	{
		if (StackSTL.top() != set_info2)
		{
			Stack2.push(StackSTL.top());
			StackSTL.pop();
		}
		else
		{
			cout << "Введите элемент, который нужно добавить в стек: ";
			cin >> a;
			Stack2.push(a);
			Stack2.push(StackSTL.top());
			StackSTL.pop();
		}
	}

	cout << "Итоговый стек: ";
	while(Stack2.empty() != true)
	{
		cout << Stack2.top() << "\t";
		Stack2.pop();
	}
}

int main()
{
	setlocale(0, "");
	system("color F0");

	cout << "РЕАЛИЗАЦИЯ ЧЕРЕЗ СТРУКТУРЫ: " << endl;

	char set_info1;
	int n1 = 0;
	while (n1 <= 0)
	{
		cout << "Введите размер списка: ";
		cin >> n1;
	}

	Stack1*stract  = Vvod1(n1);

	cout << "Начальный стек: ";
	Print1(stract);
	
	cout << "Задайте информационное поле: ";
	cin >> set_info1;
	Adding1(stract,set_info1);

	cout << "Итоговый стек: ";
	Print1(stract);

	/////////////////////////////////////////////////////////////////

	cout << "РЕАЛИЗАЦИЯ ЧЕРЕЗ БИБЛИОТЕКИ STL: " << endl;
	
	char set_info2;
	int n2 = 0;
	while (n2 <= 0)
	{
		cout << "Введите размер списка: ";
		cin >> n2;
	}

	Vvod2(n2);

	cout << "Начальный стек: ";
	Print2(n2);

	cout << "Задайте информационное поле: ";
	cin >>set_info2 ;
	Adding2(set_info2,n2);

	return 0;
}
