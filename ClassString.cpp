#include<iostream>
using namespace std;

/*
	TODO:
	������������������ �� https://github.com/ � ����������� ����������� � ���.
*/

/*
	DONE:
	1.	�������� ���� ����� �� �������
	2.	����������� �������� '+' ������ ������.
		�� ������� �� ���������� ��� �� ��������, 
		���� �� ���� ����� �� ��������. ���� ��������� �����������, �� ������ 131 � 132 ����������.
*/

class String
{
	unsigned int Size;	//������ ������
	char* Str;		//����� ������ � ������������ ������
public:
	unsigned int get_size() const
	{
		return Size;
	}
	const char* get_str() const
	{
		return Str;
	}
	//			Constructors:
	String(int Size = 80)
	{
		this->Size = Size;
		this->Str = new char[Size] {};
		cout << "DefaultConstr:\t" << this << endl;
	}
	String(const char Str[])
	{
		this->Size = strlen(Str)+1;
		this->Str = new char[Size] {};
		for (int i = 0; i < Size; i++)
		{
			this->Str[i] = Str[i];
		}
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->Size = other.Size;
		this->Str = new char[Size] {};
		for (int i = 0; i < Size; i++)
		{
			this->Str[i] = other.Str[i];
		}
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] Str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->Str;
		this->Size = other.Size;
		this->Str = new char[Size] {};
		for (int i = 0; i < Size; i++)
		{
			this->Str[i] = other.Str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String operator+(const String& other)
	{
		String Temp = this->Size + other.Size - 1;
		for (int i = 0; i < this->Size; i++)
		{
			Temp.Str[i] = this->Str[i];
		}
		for (int i = 0; i < other.Size; i++)
		{
			Temp.Str[i + this->Size - 1] = other.Str[i];
		}
		return Temp;
	}

	//				Methods:

	void shrink_to_fit()
	{
		this->Size = strlen(Str) + 1;
		char* Buffer = new char[Size] {};
		for (int i = 0; i < Size; i++)
		{
			Buffer[i] = Str[i];
		}
		delete[] Str;
		Str = Buffer;}

	void Print()
	{
		cout << "Size:\t" << Size << endl;
		cout << "Str:\t" << Str << endl;
	}

	friend istream& operator>>(istream& is, String& obj);
};

ostream& operator<<(ostream& os, const String& obj)
{
	/*os << obj.get_str();
	return os;*/
	return os << obj.get_str();
}

istream& operator>>(istream& is, String& obj)
{
	is >> obj.Str;
	obj.shrink_to_fit();
	return is;
}

//cout << Str3;
void main()
{
	setlocale(LC_ALL, "Russian");
	//String Str1;	//Default constructor
	//Str1.Print();

	//String Str2 = 8;	//Single argument constructor
	//Str2.Print();

	//String Str3 = "Hello";//Single argument constructor
	//Str3.Print();

	//String Str4 = Str3;	//CopyConstructor
	//Str4.Print();

	//String Str5;	//DefaultConstructor
	//Str3 = Str3;	//CopyAssignment
	//Str3.Print();

	/*String Str;
	cout << "������� ������: ";
	cin >> Str;
	cout << Str << endl;*/

	String Str1;
	String Str2;
	cout << "������� ����� �� ���� ����: ";
	cin >> Str1 >> Str2;
	/*Str1.shrink_to_fit();
	Str2.shrink_to_fit();*/
	String Str3 = Str1 + " " + Str2;
	cout << Str3 << endl;

	/*String Str1 = "Hello";
	String Str2 = "World";
	cout << Str1 << endl;
	cout << Str2 << endl;

	String Str3 = Str1 + " " + Str2;
	cout << Str3 << endl;*/

	/*String LastName, FirstName;
	cout << "������� ������� � ���: ";
	cin >> LastName >> FirstName;*/
	
	/*String FullName = LastName + FirstName;
	cout << FullName << endl;*/

	//Debug assertion failed ��������� � ����� �� ���� ��������:
	/*int a = 2;
	int* pa = &a;
	delete pa;*/

	/*int* Arr = new int[5]{};
	int* Buffer = Arr;
	delete[] Buffer;
	delete[] Arr;*/
}