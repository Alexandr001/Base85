/** 
* @file base85.h
* @author А.А.Попов
* @version 1.0
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля base85
*/
#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/** @brief Кодирование и декодирование base85
* @details Создаётся объект класса, а с помощью методов coder и decoder 
* осуществляется кодирование и декодирование
* @warning Реализация только для латинских символов
*/
class Base85
{
private:
	string alfabet = "&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz";
	string new_path;
	char* str;
	int len;
public:
	Base85(string file_path, string new_path);
	void coder();
	void decoder();
};
/** @brief Класс обработки ошибок base85_error
* @details Используется для вывода сообщений об ошибках
*/
class base85_error: public std::invalid_argument
{
public:
	explicit base85_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit base85_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};