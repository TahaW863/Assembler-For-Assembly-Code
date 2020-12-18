#include <iostream>
#include <string>
#include<fstream>
#include "Assembler.h"
using namespace std;
int main()
{
	/*cout << "Please, provide the name of the \"File Name\", make sure to be {fileName}.txt the same dirctory\n:";
	string name, line;
	cin >> name;
	name += ".txt";
	ifstream file(name);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << '\n';
		}
		file.close();
	}

	else cout << "Unable to open file";*/
	//cout << bitset<4>('F');
	Assembler ass;
	ass.setFileName("assembleyLangFile");
	ass.firstPass();
	ass.secondPass();
	cout << "Written By Taha.jo\n";
	return 0;
}
