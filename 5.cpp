//==============================================================
//	Name:    	Harry Mora
//	Course:  	CPSC 323
//	Project: 	3
//	Date:    	September 29, 2013
//	Professor:  Ray Ahmadnia
//	Purpose: 	Read from data.txt, tokenize and analyze content
//==============================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class CLEAN{
		private:
				fstream f;
				string token;
				string temp_token, temp_string;
				vector <string> input;
				vector <string> input_st;
				vector<string>::iterator it;
				int size, comma, period, semicolon;
				int counter, p;
				
				bool isIdentifier;
				bool isInteger;
				bool isRealNumber;
				bool isReservedWord;
				
		public:
				void readData(){
						f.open("data.txt", ios::in);
						if(!f){
						cout << "File not found";
						}
						while( !f.eof() ){
								cout << "hello" << endl;
								//f >> token;
								//input.push_back(token);
						}
				}
				void removeComments(){}
				void removeSpaces(){}
				
};

int main(){

CLEAN A;
A.readData();

return(0);
}

/* SAMPLE IO

*/