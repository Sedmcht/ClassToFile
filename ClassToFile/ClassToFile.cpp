#include <iostream>
#include <filesystem>
#include "User.h"
#include "Message.h"

using namespace std;

int main()
{

	fstream user_file = fstream("users.txt", ios::in | ios::out);
	if (!user_file)
	{
		// Для создания файла используем параметр ios::trunc
		user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
		filesystem::permissions("users.txt", filesystem::perms::group_write | filesystem::perms::group_read | filesystem::perms::others_all,
			filesystem::perm_options::remove);
	}

	if (user_file) {
		User obj("Alex", "qwerty", "12345");
		// Запишем данные по в файл
		user_file << obj << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		user_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}


	fstream message_file = fstream("message.txt", ios::in | ios::out);
	if (!message_file)
	{
		// Для создания файла используем параметр ios::trunc
		message_file = fstream("message.txt", ios::in | ios::out | ios::trunc);
		filesystem::permissions("message.txt", filesystem::perms::group_write | filesystem::perms::group_read | filesystem::perms::others_all,
			filesystem::perm_options::remove);
	}

	if (message_file) {
		Message obj("Hello", "ALex", "Alex");
		// Запишем данные по в файл
		message_file << obj << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		message_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		message_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file message.txt !" << '\n';
		return 0;
	}


}

