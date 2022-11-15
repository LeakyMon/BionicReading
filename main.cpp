#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void numLetters(string word, ofstream& output) {

	string temp = "";

	for (int i = 0; i <= word.size(); i++) {
		
		if (i == word.size()){
			output << "<b>" << "</b>" << temp << " ";
		}
		else if (word.at(i) != ' ') {
			temp.push_back(word.at(i));
		}
		else {
			
			string out = temp;
			if (temp.size() == 1) {
				out.pop_back();
			}
			else if (temp.size() == 2) {
				out.pop_back();
				out.pop_back();
			}
			else if (temp.size() == 3) {
				out.pop_back();
				out.pop_back();
				temp.erase(0, 1);
			}
			else if (temp.size() == 4) {				
				out.pop_back();
				out.pop_back();			
				temp.erase(0, 2);				
			}
			else if (temp.size() == 5) {
				out.pop_back();
				out.pop_back();			
				temp.erase(0, 3);		
			}
			else if (temp.size() == 6) {
				out.pop_back();
				out.pop_back();
				out.pop_back();			
				temp.erase(0, 3);
			}
			else if (temp.size() == 7) {
				out.pop_back();
				out.pop_back();
				out.pop_back();
				temp.erase(0, 4);	
			}
			else if (temp.size() == 8) {
				out.pop_back();
				out.pop_back();
				out.pop_back();
				out.pop_back();
				temp.erase(0, 4);
				
			}
			else if (temp.size() == 9) {
				out.pop_back();
				out.pop_back();
				out.pop_back();
				out.pop_back();				
				temp.erase(0, 5);				
			}
			else if (temp.size() > 9) {
				out.pop_back();
				out.pop_back();
				out.pop_back();
				out.pop_back();
				out.pop_back();
				int eraser = temp.size() - 5;		
				temp.erase(0, eraser);
			}
			output << "<b>" << out << "</b>" << temp << " ";	
			temp = "";
		}
	}
}

int main() {

	ifstream inFile;
	ofstream product("output.txt");
	inFile.open("FILENAME_HERE.txt");

	if (inFile.is_open()) {
		cout << "Open" << endl;
	}

	string temp;
	int x = 0;
	while (getline(inFile, temp)) {
		numLetters(temp, product);
		product << "<br>" << endl;
	}
	return 0;
}