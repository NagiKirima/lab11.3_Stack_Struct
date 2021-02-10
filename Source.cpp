#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct List
{
	int data;
	List* next_block;
	List* prev_block;
};
int GetSize()
{
	int size;
	while (!(cin >> size) || (cin.peek() != '\n') || (size < 1))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			cout << "Введите корректное число!\t";
		}
	}
	return size;
}
int GetInt()
{
	int num;
	while (!(cin >> num) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			cout << "Введите корректное число!\t";
		}
	}
	return num;
}
List* Create_list(int size)
{
	List* first_element = nullptr;
	List* current_element;
	if (size == 1)
	{
		cout << "Введите 0-й элемент стека:\t";
		current_element = new List;
		current_element->data = GetInt();
		first_element = current_element;
		current_element->next_block = nullptr;
		current_element->prev_block = nullptr;
	}
	else
	{
		cout << "Введите 0-й элемент стека:\t";
		current_element = new List;
		current_element->data = GetInt();
		first_element = current_element;
		current_element->next_block = nullptr;
		current_element->prev_block = nullptr;
		for (int i = 1; i < size; i++)
		{
			cout << "Введите " << i << "-й элемент стека:\t";
			List* new_element = new List;
			current_element->next_block = new_element;
			new_element->prev_block = current_element;
			current_element = new_element;
			current_element->data = GetInt();
			current_element->next_block = nullptr;
		}
	}
	return first_element;
}
List* Pop(List* first_element)
{
	List* tmp = first_element;
	while (tmp->next_block != nullptr)
	{
		tmp = tmp->next_block;
	}
	if (tmp->prev_block != nullptr)
	{
		List* predtmp = tmp->prev_block;
		delete tmp;
		predtmp->next_block = nullptr;
	}
	else
	{
		delete tmp;
		tmp = nullptr;
		first_element = nullptr;
	}
	return first_element;
}
List* Push_list(List* first_element, int value)
{
	List* current_element = first_element;
	if (first_element == nullptr)
	{
		first_element = new List;
		first_element->data = value;
		first_element->next_block = nullptr;
		first_element->prev_block = nullptr;
	}
	else
	{
		{
			while (current_element->next_block != nullptr)

				current_element = current_element->next_block;
		}
		List* new_element = new List;
		new_element->data = value;
		new_element->next_block = nullptr;
		new_element->prev_block = current_element;
		current_element->next_block = new_element;
	}
	return first_element;
}
void Print_list(List*& first_element)
{
	vector <int> tmp;
	List* current_element = first_element;
	// проход до последнего элемента стека
	int i = 0;
	if (first_element == nullptr)
	{
		cout << "Список пуст!" << endl;
		return;
	}
	while (current_element->next_block != nullptr)
	{
		current_element = current_element->next_block;
		i++;
	}
	while (i >= 0)
	{
		cout << i << "-й элемент стека:\t" << current_element->data << endl;
		i--;
		List* temp = current_element;
		current_element = current_element->prev_block;
		tmp.push_back(temp->data);
		first_element = Pop(first_element);
	}
	int j = tmp.size() - 1;
	while (j >= 0)
	{
		first_element = Push_list(first_element, tmp[j]);
		j--;
	}
}
bool Delete_element(List*& first_element)
{
	vector <int> tmp;
	bool check = false;
	List* current_element = first_element;
	//проход до вершины стека
	int i = 0;
	while (current_element->next_block != nullptr)
	{
		current_element = current_element->next_block;
		i++;
	}
	while (i >= 0)
	{
		List* temp = current_element;
		current_element = current_element->prev_block;
		tmp.push_back(temp->data);
		first_element = Pop(first_element);
		i--;
	}

	for (int j = 0; j < tmp.size(); j++)
	{
		if (tmp[j] % 2 == 0)
		{
			tmp.erase(tmp.begin() + j);
			check = true;
			break;
		}
		
	}
	for (int k = tmp.size() - 1; k >= 0; k--)
	{
		first_element = Push_list(first_element, tmp[k]);
	}
	return check;
}
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите размер стека:\t";
	int size = GetSize();
	List* stack = Create_list(size);
	cout << "============================\n";
	Print_list(stack);
	cout << "============================\n";
	if (Delete_element(stack))
	{
		Print_list(stack);
	}
	else
	{
		cout << "Четных элементов в стеке нет!\n";
		Print_list(stack);
		cout << "============================\n";
	}
}