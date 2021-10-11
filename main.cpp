/** 
* @file main.cpp
* @brief Главный модуль base85.
*/
#include "base85.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	string file_path, new_path;
	string vote;
	
	try
	{
		cout << "Input file way" << endl;
		cin >> file_path;
		
		cout << "Input save file way" << endl;
		cin >> new_path;
		
		Base85 q(file_path, new_path);
		
		cout << "Inpute mode\n1.Code\n2.Decode\nANY.Exit" << endl;
		cin >> vote;
		
		if (vote == "1"){
			q.coder();
		}else if (vote == "2"){
			q.decoder();
		}else
			cout << "exit..." << endl;
			
	}catch (const base85_error & e){
		std::cerr << e.what() << std::endl;
	}
}