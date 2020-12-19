#include <iostream>
#include <string>
#include<fstream>
#include "Assembler.h"
using namespace std;
int main()
{
	cout << "Please, provide the name of the \"File Name\", make sure to be {fileName}.txt the same dirctory\n:";
	string name;
	cin >> name;
	Assembler ass;
	//ass.setFileName("assembleyLangFile");
	ass.setFileName(name);
	ass.firstPass();
	ass.secondPass();
	cout << "\nWritten By Taha.jo\n";
	return 0;
}
