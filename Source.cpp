/* This program encrypts a user entered string and then decrypts it.
The encryption function asks for a user input number from 0-9, increases the ASCII value
of the characters by that number and then reverses the string. 
The decryption function then reverses the string and reduces the ASCII value of the characters
to regenerate the original string.
The decryption string is the exact reverse of the encryption function.
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char* encrypt(char *, int);
char* decrypt(char *, int);

int main()
{
	const int MAX_SIZE = 46;
	char words[MAX_SIZE];
	int secretCode;

	cout << "Please enter a number from 0 to 9: ";		//Get secretCode from user
	cin >> secretCode;
	cout << "\n Please enter a sentence: ";				//Get string input from user
	cin.ignore();
	cin.getline(words, MAX_SIZE);
	cout << endl;

	encrypt(words, secretCode);							//encrypt string using Encrypt function
	cout << "Your encrypted string reads: \n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << words[i];
	}
	cout << endl;
	cout << endl;

	decrypt(words, secretCode);							//decrypt string using Decrypt function
	cout << "Your decrypted string reads: \n";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << words[i];
	}
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}

char* encrypt(char *str, int num)							//encrypt function definition
{
	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		*(str + i) = char(int(*(str + i)) + num);
	}

	for (int i = 0; i < length / 2; i++)
	{
		//char temp = ' ';
		char temp = *(str + i);
		*(str + i) = *(str + length - 1 - i);
		*(str + length - 1 - i) = temp;
	}
	return str;
}

char* decrypt(char *str, int num)						//decrypt function definition
{
	int length = strlen(str);

	for (int i = 0; i < length / 2; i++)
	{
		//char temp = ' ';
		char temp = *(str + i);
		*(str + i) = *(str + length - 1 - i);
		*(str + length - 1 - i) = temp;
	}


	for (int i = 0; i < length; i++)
	{
		*(str + i) = char(int(*(str + i)) - num);
	}

	return str;
}
