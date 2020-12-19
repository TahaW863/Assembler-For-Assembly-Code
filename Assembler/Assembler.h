#ifndef ASSEMBLER
#define ASSEMBLER
#include<vector>
#include<set>
#include<map>
#include <utility>
#include <iostream>
#include<fstream>
#include<bitset>
#include<string>
#include<assert.h>
#include <sstream> 
using namespace std;
class Assembler
{
public:
	Assembler();
	void setFileName(string fileName);
	//TODO: function for first ass
	void firstPass();
	//TODO: function for the second ass
	void secondPass();
private:
	string lookUp(string, bool);
	string bitSTRING(char);
	void printAddressSymbolTABLE();
	string fileName;
	int N, begin;
	bool flag;
	set<string> labelSet;
	//map<string, string> pseudoInstruction;
	set< string> MRI;
	set< string> NonMRI;
	set<string> InOuput;
	set<string> addressFirstPass;
	vector<pair<string, int>> addressSymbol;
};
#endif
