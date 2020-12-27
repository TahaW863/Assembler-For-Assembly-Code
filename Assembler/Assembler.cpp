#include "Assembler.h"
std::string::size_type sz;
string string_to_hex(const std::string& in) {
	std::stringstream ss;

	ss << std::hex << setfill('0');
	for (size_t i = 0; in.length() > i; ++i) {
		ss << setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(in[i]));
	}

	return ss.str();
}
int convert(string num) {
	int len = num.length();
	int base = 1;
	int temp = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] >= '0' && num[i] <= '9') {
			temp += (num[i] - 48) * base;
			base = base * 16;
		}
		else if (num[i] >= 'A' && num[i] <= 'F') {
			temp += (num[i] - 55) * base;
			base = base * 16;
		}
	}
	return temp;
}
Assembler::Assembler() {
	//MRI TABLE
	MRI.insert("AND");
	MRI.insert("ADD");
	MRI.insert("LDA");
	MRI.insert("STA");
	MRI.insert("BUN");
	MRI.insert("BSA");
	MRI.insert("ISZ");

	//NON-MRI TABLE
	NonMRI.insert("CLA");
	NonMRI.insert("CLE");
	NonMRI.insert("CMA");
	NonMRI.insert("CME");
	NonMRI.insert("CIR");
	NonMRI.insert("CIL");
	NonMRI.insert("INC");
	NonMRI.insert("SPA");
	NonMRI.insert("SNA");
	NonMRI.insert("SZA");
	NonMRI.insert("SZE");
	NonMRI.insert("HLT");

	//INPUT OUTPUT TABLE
	InOuput.insert("INP");
	InOuput.insert("OUT");
	InOuput.insert("SKI");
	InOuput.insert("SKO");
	InOuput.insert("ION");
	InOuput.insert("IOF");
	
	//N
	N = 0;
	begin = 0;
	//flag
	flag = 0;
}
string Assembler::lookUp(string code,bool indir) {
	//MRI TABLE STRING
	if (code == "AND") {
		if (indir) {
			return bitSTRING('8');
		}
		else {
			return bitSTRING('0');
		}
	}
	if (code == "ADD") {
		if (indir) {
			return bitSTRING('9');
		}
		else {
			return bitSTRING('1');
		}
	}
	if (code == "LDA") {
		if (indir) {
			return bitSTRING('A');
		}
		else {
			return bitSTRING('2');
		}
	}
	if (code == "STA") {
		if (indir) {
			return bitSTRING('B');
		}
		else {
			return bitSTRING('3');
		}
	}
	if (code == "BUN") {
		if (indir) {
			return bitSTRING('C');
		}
		else {
			return bitSTRING('4');
		}
	}
	if (code == "BSA") {
		if (indir) {
			return bitSTRING('D');
		}
		else {
			return bitSTRING('5');
		}
	}
	if (code == "ISZ") {
		if (indir) {
			return bitSTRING('E');
		}
		else {
			return bitSTRING('6');
		}
	}
	//NON MRI
	if (code == "CLA") {
		return "7800";
	}
	if (code == "CLE") {
		return "7400";
	}
	if (code == "CMA") {
		return "7200";
	}
	if (code == "CME") {
		return "7100";
	}
	if (code == "CIR") {
		return "7080";
	}
	if (code == "CIL") {
		return "7040";
	}
	if (code == "INC") {
		return "7020";
	}
	if (code == "SPA") {
		return "7010";
	}
	if (code == "SNA") {
		return "7008";
	}
	if (code == "SZA") {
		return "7004";
	}
	if (code == "SZE") {
		return "7002";
	}
	if (code == "HLT") {
		return "7001";
	}
	//INPUT OUTPUT
	if (code == "INP") {
		return "F800";
	}
	if (code == "OUT") {
		return "F400";
	}
	if (code == "SKI") {
		return "F200";
	}
	if (code == "SKO") {
		return "F100";
	}
	if (code == "ION") {
		return "F080";
	}
	if (code == "IOF") {
		return "F040";
	}
}
string Assembler::bitSTRING(char c) {
	switch (c) {
	case '0':
		return  "0000";
		break;
	case '1':
		return  "0001";
		break;
	case '2':
		return  "0010";
		break;
	case '3':
		return  "0011";
		break;
	case '4':
		return  "0100";
		break;
	case '5':
		return  "0101";
		break;
	case '6':
		return  "0110";
		break;
	case '7':
		return  "0111";
		break;
	case '8':
		return  "1000";
		break;
	case '9':
		return  "1001";
		break;
	case 'A':
	case 'a':
		return  "1010";
		break;
	case 'B':
	case 'b':
		return  "1011";
		break;
	case 'C':
	case 'c':
		return  "1100";
		break;
	case 'D':
	case 'd':
		return  "1101";
		break;
	case 'E':
	case 'e':
		return  "1110";
		break;
	case 'F':
	case 'f':
		return  "1111";
		break;
	default:
		break;
	}
}
void Assembler::setFileName(string fileName) {
	this->fileName = fileName+".txt";
}
void Assembler::firstPass() {
	string line;
	bool fir = true, comma = false;
	ifstream file(fileName);
	
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (fir) {
				if (line.find("ORG") == -1) {
					stringstream s("0");
					s >> hex >> begin;
					N = 0;
				}
				fir = false;
			}
			stringstream ss(line);
			string temp;
			ss >> temp;
			if (temp == "ORG") {
				ss >> temp;
				
				stringstream sx(temp);
				sx >> std::hex >> begin;
				 N= stoi(temp, &sz);
				 //cout << temp << endl;
				 continue;
			}
			if (temp == "END") {
				break;
			}
			if (NonMRI.count(temp) > 0 or InOuput.count(temp) > 0) {
				string shit;
				ss >> shit;
				if (shit!="") {
					flag = 1; break;
				}
				++N;
				continue;
			}
			if(temp.find(',')!=-1)
			temp = temp.substr(0, temp.length() - 1);
			if (addressFirstPass.count(temp) > 0) {
				addressSymbol.push_back(make_pair(temp, N));
				++N;
				continue;
			}

			if (addressFirstPass.count(to_string(N)) > 0) {
				
				int num;
				if (temp == "HEX") {
					
					ss >> temp;
					stringstream sx(temp);
					sx >> hex >> num;
					
				}
				if (temp == "DEC") {
					

					num = stoi(temp, &sz);
					
				}
				addressSymbol.push_back(make_pair(to_string(N),num));
			}
			//IF ITS NOT INPUT OUTPUT OR NON-MRI
			ss >> temp;
			
			if (temp.length() > 3&&!isxdigit(temp[0])) {
				cout << temp << endl;
				flag = true;
				break;
			}
			if (isxdigit(temp[0])) {
				stringstream sd(temp);
				int num;
				sd >> hex >> num;
				addressFirstPass.insert(to_string(num));
			}else
			addressFirstPass.insert(temp);
			++N;
		}
		printAddressSymbolTABLE();
		file.close();
	}

	else assert("Unable to open file");
}
void Assembler::printAddressSymbolTABLE() {
	if (flag ) {
		flag = true;
		return;
	}
	//should not pass if the number of address syb not equal to the first
	cout << "Symbolic Table:\n";
	for (int i = 0; i < addressSymbol.size(); i++) {
		if(!isdigit(addressSymbol[i].first[0]))
		cout << addressSymbol[i].second << ' ' << addressSymbol[i].first << endl;
	}cout << endl;
}
void Assembler::secondPass() {
	if (flag) {
		cout << ":INVALID SIZE:";
		return;
	}
	cout << "Address            Content\n";
	ifstream myfile(fileName);
	string line;
	bool fir = true,comma=false;
	string temp;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (fir) {
				fir = false;
				continue;
			}
			stringstream ss(line);
			ss >> temp;
			if (temp == "END") {
				break;
			}
			if (temp == "HEX") {
				cout << bitset<12>(convert(to_string(begin++))) << "   ";
				string s;
				ss >>s;
				cout << bitset<16>(convert(s)) << endl;
				continue;
			}
			else if (temp == "DEC") {
				cout << bitset<12>(convert(to_string(begin++))) << "   ";
				int num;
				ss >> hex >> num;
				cout << bitset<16>(num) << endl;
				continue;
			}
			if (MRI.count(temp) > 0) {
				bool indir = false;
				int len = line.length();
				for (int i = 0; i < len; i++) {
					if (i > 1 && line[i] == 'I' && isspace(line[i - 1])) {
						indir = true;
					}
				}
				cout << bitset<12>(convert(to_string(begin++))) << "   " << lookUp(temp, indir);
				ss >> temp;
				int num = -1;
				for (int i = 0; i < addressSymbol.size(); i++) {
					if (addressSymbol[i].first == temp) {
						num = addressSymbol[i].second;
						break;
					}
				}
				if (num == -1) {
					num = convert(temp);
					num = convert(to_string(num));
				}
				cout << bitset<12>(num) << endl;
				continue;
			}
			
			//back
			if (line.find(',')!=-1 or addressFirstPass.count(to_string(N)) > 0) {
				
				ss >> temp;
				bool dec = false;
				
					dec = true;

				
					int num;
					
					if (temp == "HEX") {
						cout << bitset<12>(convert(to_string(begin++))) << "   ";
						ss >> hex >> num;
						cout << bitset<16>(num) << endl;
						continue;
					}
					if (temp == "DEC") {
						cout << bitset<12>(convert(to_string(begin++))) << "   ";

						num = stoi(temp, &sz);
						cout << bitset<16>(num) << endl;
						continue;
					}
				
				
			}
			
			if (NonMRI.count(temp) > 0) {
				cout << bitset<12>(convert(to_string(begin++))) << "   ";
				string hexFromLook = lookUp(temp, true);
				for (int i = 0; i < hexFromLook.length(); i++) {
					cout << bitSTRING(hexFromLook[i]);
				}cout << endl;
				continue;
			}
			if (InOuput.count(temp) > 0) {
				cout << bitset<12>(convert(to_string(begin++))) << "   ";
				string hexFromLook = lookUp(temp, true);
				for (int i = 0; i < hexFromLook.length(); i++) {
					cout << bitSTRING(hexFromLook[i]);
				}cout << endl;
				continue;
			}

		}
		myfile.close();
	}

	else cout << "Unable to open file";
}
