#include <iostream>
#include <ctime>
using namespace std;

//class Fraction
//{
//	friend Fraction operator *(int left, Fraction right)
//	{
//		return right * left;
//	}
//public:
//	int numerator; 
//	int denominator;
//	Fraction()
//	{
//		cout << "Введите числитель: ";
//		cin >> numerator;
//		cout << "Введите знаминатель: ";
//		cin >> denominator;
//	}
//	Fraction(int Numerator, int Denominator)
//	{
//		numerator = Numerator;
//		denominator = Denominator;
//	}
//	void Assign(int Numerator, int Denominator)
//	{
//		numerator = Numerator;
//		denominator = Denominator;
//	}
//	void Print()
//	{
//		cout << numerator << "/" << denominator << "\n";
//	}
//	void Mul(Fraction a)
//	{
//		Assign(numerator * a.numerator, denominator * a.denominator);
//	}
//	void Div(Fraction a)
//	{
//		Assign(numerator * a.denominator, denominator * a.numerator);
//	}
//	void Sum(Fraction a)
//	{
//		Assign(numerator * a.denominator + denominator * a.numerator, denominator * a.denominator);
//	}
//	void Sub(Fraction a)
//	{
//		Assign(numerator * a.denominator - denominator * a.numerator, denominator * a.denominator);
//	}
//	Fraction operator +(const Fraction a)
//	{
//		Fraction r(numerator, denominator);
//		r.Sum(a);
//		return r;
//	}
//	Fraction operator -(Fraction a)
//	{
//		Fraction r(numerator, denominator);
//		r.Sub(a);
//		return r;
//	}
//	Fraction operator /(Fraction a)
//	{
//		Fraction r(numerator, denominator);
//		r.Div(a);
//		return r;
//	}
//	Fraction operator *(Fraction a)
//	{
//		Fraction r(numerator, denominator);
//		r.Mul(a);
//		return r;
//	}
//	Fraction operator *(int a)
//	{
//		 return Fraction(numerator * a, denominator);
//	}
//};
//
//int main()
//{
//	Fraction f1;
//	Fraction f2;
//
//	//f1.Print();
//	//f2.Print();
//	//
//	//f1.Mul(f2);
//	//f1.Print();
//	//
//	//f1.Div(f2);
//	//f1.Print();
//	//
//	//f1.Sum(f2);
//	//f1.Print();
//	//
//	//f1.Sub(f2);
//	//f1.Print();
//	f1.Print();
//	f2.Print();
//	Fraction f3 = f1 + f2;
//	f3.Print();
//	f3 = f1 - f2;
//	f3.Print();
//	f3 = f1 / f2;
//	f3.Print();
//	f3 = f1 * f2;
//	f3.Print();
//	f1 = f3 * 2;
//	f1.Print();
//	f1 = 2 * f3;
//	f1.Print();
//	
//}

class MyString
{
	friend MyString operator +(int delta, MyString right)
	{
		char mas[1000];
		for (int i = 0; i < delta; i++)
		{
			mas[i] = 'x';
		}
		for (int i = 0; i < right.size; i++)
		{
			mas[delta + i] = right.str[i];
		}
		mas[delta + right.size] = 0;
		return MyString(mas);
	}
	int size = 0;
	char* str = nullptr;
public:
	
	static int count;
	MyString()
	{
		Clear();
		str = new char[80];
		size = 80;
		for (int i = 0; i < size; i++) str[i] = '*'; 
		str[size - 1] = 0;
		count++;
	}
	MyString(const MyString& r)
	{
		SetStr(r.str);
		count++;
	}
	MyString(int size)
	{
		Clear();
		str = new char[size + 1];
		this->size = size;
		str[size - 1] = 0;
		for (int i = 0; i < size; i++) str[i] = '*';
		count++;
	}
	MyString(const char* str)
	{
		SetStr(str);
		count++;
	}
	~MyString()
	{
		Clear();
		count--;
	}
	void SetStr(const char* str)
	{
		Clear();
		int length = strlen(str);
		this->str = new char[length + 1];
		this->size = length;
		for (int i = 0; i <= length; i++)
		{
			this->str[i] = str[i];
		}
	}
	void Clear()
	{
		if (str != nullptr)
		{
			delete[] str;
		}
	}
	void Print()
	{
		cout << str << endl;
	}
	static int GetCount()
	{
		return count;
	}
	void Read(const char* mesagge)
	{
		char mas[250];
		cout << mesagge << ": ";
		cin.getline(mas, 250);
		SetStr(mas);
	}
	MyString operator +(int delta)
	{
		if (delta < 0) return *this - (-delta);
		char mas[1000];
		for (int i = 0; i < size; i++)
			mas[i] = str[i];
		for (int i = 0; i < delta; i++)
			mas[size + i] = 'x';
		mas[size + delta] = 0;
		return MyString(mas);
	}
	MyString operator -(int delta)
	{
		if (delta < 0) return *this + (-delta);
		char mas[1000];
		int newsize = size - delta;
		if (newsize < 0) newsize = 0;
		for (int i = 0; i < newsize; i++)
			mas[i] = str[i];
		mas[newsize] = 0;
		return MyString(mas);
	}
	void Plus(int delta)
	{
		if (delta < 0) return Minus(-delta);
		char mas[1000];
		for (int i = 0; i < size; i++)
			mas[i] = str[i];
		for (int i = 0; i < delta; i++)
			mas[size + i] = 'x';
		mas[size + delta] = 0;
		SetStr(mas);
	}
	void Minus(int delta)
	{
		if (delta < 0) return Plus(-delta);
		char mas[1000];
		int newsize = size - delta;
		if (newsize < 0) newsize = 0;
		for (int i = 0; i < newsize; i++)
			mas[i] = str[i];
		mas[newsize] = 0;
		SetStr(mas);
	}

	MyString operator ++()
	{
		Plus(1);
		return MyString(*this);

	}

	MyString operator --()
	{
		Minus(1);
		return MyString(*this);
	}
};
int MyString::count = 0;

int main()
{
	
	int k = 2;
	MyString str1;
	str1.Read("Введите 1 строку");
	str1.Print();
	/*MyString str2 = str1 + (-4);
	str2.Print();
	
	MyString str3 =  str1 + 3;
	str3.Print();
	MyString str4 = ++str3;
	str3.Print();
	str4.Print();
	MyString str5 = --str4;
	str4.Print();
	str5.Print();*/
	MyString str6 = k + str1;
	str6.Print();
}












