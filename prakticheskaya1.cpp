#include <iostream>

using namespace std;

short int menu()
{
	short int i;
    cout << "������� ����� ������������ ������:\n";
	cout << "1) ������� ���������� ������ (� ������) ���������� ��� ��������� � ����\n";
	cout << "2) ������� �������� ������������� � ������ int �����\n";
	cout << "3) ������� �������� ������������� � ������ float �����\n";
	cout << "4) �����\n";
	while (1)
	{
		cin >> i;
		if (i > 0 & i < 5)
			break;
		else
			cout << "������� ��������� ������\n";
	}
	cout << "\n";
	return i;	
}

void size_of()
{
	cout << "int - " << sizeof(int) << "\n";
	cout << "short int - " << sizeof(short int) << "\n";
	cout << "long int - " << sizeof(long int) << "\n";
	cout << "float - " << sizeof(float) << "\n";
	cout << "double - " << sizeof(double) << "\n";
	cout << "long double - " << sizeof(long double) << "\n";
	cout << "char - " << sizeof(char) << "\n";
	cout << "bool - " << sizeof(bool) << "\n\n";
}

void conclusion_int()
{
	int value = 0, massiv_chisel[32];
	cout << "������� ����� �����: ";
	cin >> value;
	unsigned int mask = 1 << 31;
	cout << "� �������� ����: \n";
	for (int i = 0; i < 32; i++)
	{
		if (value & mask)
			massiv_chisel[i] = 1;
		else
			massiv_chisel[i] = 0;
		putchar(value & mask ? '1' : '0'); 
		value <<= 1;
		if (i == 0)
			putchar(' ');
	}
	cout << "\n";
	cout << "�������������� �������\n";
	for (int i = 1; i <= 32; i++)
	{
		if (massiv_chisel[0] == 0)
		{
			if (i % 2 == 0)
				massiv_chisel[i - 1] = 0;
		}
		if (massiv_chisel[0] == 1)
		{
			if (i % 2 == 1)
				massiv_chisel[i - 1] = 1;
		}
		cout << massiv_chisel[i - 1];
		if (i == 1)
			putchar(' ');
	}
	cout << "\n\n";
}

void conclusion_float()
{
	union
	{
		float value;
		int floatvalue;
	};
	int massiv_chisel[32];
	cout << "������� ������������ �����: ";
	cin >> value;
	unsigned int mask = 1 << 31;
	cout << "� �������� ����: \n";
	for (int i = 0; i < 32; i++)
	{
		if (floatvalue & mask)
			massiv_chisel[i] = 1;
		else
			massiv_chisel[i] = 0;
		putchar(floatvalue & mask ? '1' : '0'); 
		floatvalue <<= 1;
		if (i == 0 || i == 8)
			putchar(' ');
	}
	cout << "\n";
	cout << "�������������� �������\n";
	for (int i = 1; i <= 32; i++)
	{
		if (massiv_chisel[0] == 0)
		{
			if (i % 2 == 0)
				massiv_chisel[i - 1] = 0;
		}
		if (massiv_chisel[0] == 1)
		{
			if (i % 2 == 1)
				massiv_chisel[i - 1] = 1;
		}
		cout << massiv_chisel[i - 1];
		if (i == 1 || i == 9)
			putchar(' ');
	}
	cout << "\n\n";
}

int main()
{
	setlocale (LC_ALL, "Russian");
	short int choose_menu, exit = 0;
	
	while (1)
	{
		choose_menu = menu();
		switch (choose_menu)
        	{
            	case 1:
            		size_of();
            	break;
           		case 2:
            	   conclusion_int();
            	break;
            	case 3:
            	   conclusion_float();
            	break;
            	case 4:
            	   exit = 1;
            	break;  
    	}
    	if (exit == 1)
    		break;
	}	
}
