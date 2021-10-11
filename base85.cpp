/**
 * @file base85.cpp
 */
#include "base85.h"
/**
* @brief Конструктор
* @param file_path - путь к файлу который будет зашифрован/дешифрован
* @param new_path - путь к файлу в который будет осуществлено шифрование/дешифрование
* @throw base85_error, если произошла ошибка.
*/
Base85::Base85(string file_path, string new_path)
{
	if(file_path.empty() || new_path.empty())
		throw base85_error("Error file");

	if(file_path.find(".") == -1 || new_path.find(".") == -1)
		throw base85_error("Error file");

	bool letter = 0;
	for(auto s : file_path)
		if(s > 64 && s < 91 || s > 96 && s < 123) {
			letter = true;
			break;
		}
	if(!letter)
		throw base85_error("Error file");
	letter = 0;
	for(auto s : new_path)
		if(s > 64 && s < 91 || s > 96 && s < 123) {
			letter = true;
			break;
		}
	if(!letter)
		throw base85_error("Error file");

	int pos = file_path.rfind(".");
	if (pos == string::npos)
		throw base85_error("Error file!");
	if(file_path.substr(pos + 1).empty())
		throw base85_error("Error file!");
	pos = new_path.rfind(".");
	if (pos == string::npos)
		throw base85_error("Error file!");
	if(new_path.substr(pos + 1).empty())
		throw base85_error("Error file!");
	
	this->new_path = new_path;
	// Путь к файлу
	ifstream file(file_path, ios::binary);
	if (!file)
		throw base85_error("Error open file");

	file.seekg(0, file.end);
	this->len = file.tellg();
	file.seekg(0, file.beg);
	this->str = new char[len + 1];
	file.read(str, len);
}
/**
* @brief Кодирование
* @throw base85_error, если произошла ошибка.
*/
void Base85::coder()
{
	string output("");
	int a = len, b = a * 8 / 6;
	if (a * 8 % 6 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 8];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++) {
		for (int k = 1; k < 9; k++) {
			buff[j] = (str[i - 1] >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	for (int l = 0; l < b; l++) {
		q[l] = 0;
		for (int i = 0; i < 6; i++) {
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += alfabet[(unsigned int)q[l]];
	}
	
	ofstream file(new_path, ios::binary);
	file << output;
}
/**
* @brief Декодирование
* @throw base85_error, если произошла ошибка.
*/
void Base85::decoder()
{
	string output("");
	int a = len, b = a * 6 / 8;
	if (a * 6 % 8 != 0)
		b++;
	unsigned char *q;
	bool *buff;
	int j = 0;
	buff = new bool[a * 6];
	q = new unsigned char[b];
	for (int i = 1; i < a + 1; i++) {
		for (int k = 1; k < 7; k++) {
			for (int l = 0; l < 85; l++)
				if (str[i - 1] == alfabet[l])
					buff[j] = (l >> (k - 1)) & 1;
			j++;
		}
	}
	int num = 0;
	for (int l = 0; l < b; l++) {
		q[l] = 0;
		for (int i = 0; i < 8; i++) {
			if (buff[num] == 1)
				q[l] = q[l] | (1 << i);
			num++;
		}
		output += q[l];
	}
	
	ofstream file(new_path, ios::binary);
	file << output;
}
