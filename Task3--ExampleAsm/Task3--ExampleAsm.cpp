#include <iostream>
using namespace std;

int main()
{
	bool signOverflowFlag, unsignOverflowFlag;
	unsigned char summWithout;
	signed char summWithSign;
	unsigned char a, b;
	cout << "Write two numbers: " << endl;
	cin >> a >> b;
	__asm
	{
		// Для начала приравняваем нашим регистрам "firstNumber" и "secondNumber" наши значения a,b, введенные пользователем
		// а также приравняем наши "булевы" значения к 0 для нашего удобства
		mov signOverflowFlag, 0
		mov unsignOverflowFlag, 0
		mov al, a
		mov dl, b

		add al, dl //складываем

		mov summWithout, al
		mov summWithSign, al

		jno noSignOverflow
		mov signOverflowFlag, true
	noSignOverflow: //если тут нет переполнения, то программа "пойдет" дальше

		jnc noUnsignOverflow //еще одна проверка
        mov unsignOverflowFlag, 1

	noUnsignOverflow:
		
	}
	cout << "a + b = " << summWithout << endl;
	cout << "a + b = " << summWithSign << endl;

	cout << "There was " << (signOverflowFlag ? "" : "no ") << "signed overflow" << endl;
	cout << "There was " << (unsignOverflowFlag ? "" : "no ") << "unsigned overflow" << endl;
}

