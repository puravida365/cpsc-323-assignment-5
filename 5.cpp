//==============================================================
//	Name:    	Samar Alqayidi, Harry Mora
//	Course:  	CPSC 323
//	Project: 	5
//	Date:    	October 17, 2013
//	Professor:  Ray Ahmadnia
//	Purpose: 	Program reads c++ code from a file and removes
//              comment lines, unwanted spaces, then places a
//              space between all tokens
//==============================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>


using namespace std;

class STRIP{
		private:
				fstream f;
				vector <string> T;
				vector <string> X;
				vector <string>::iterator iter;
				string line;
				string s;
				int n;

		public:
				void readData(){
					f.open("data.txt", ios::in);
					if(!f){
						cout << "File not found";
					}
					while(getline(f, line)){
						T.push_back(line);
					}
				}
				void cleanData(){
				
					for (iter = T.begin(); iter != T.end(); iter++){
						s = *iter;
						n = s.length();
						for(int j = 0; j < 3; j++){
							for(int i = 0; i < n; ++i){
								// remove extra spaces
								if((s[i] == ' ')&&(s[i+1] == ' ')){
									s.erase(i,1);
								}
								// remove spaces between parentheses
								else if((s[i] == '(')&& (s[i+1] == ' ')){
									s.erase(i+1,1);
								}
								// remove spaces before comma
								else if((s[i] == ' ')&& (s[i+1] == ',')){
									s.erase(i,1);
								}
								// remove spaces after comma
								else if((s[i] == ',')&& (s[i+1] == ' ')){
									s.erase(i+1,1);
								}
								// remove spaces before semicolon
								else if((s[i] == ' ')&& (s[i+1] == ';')){
									s.erase(i,1);
								}
								// remove comments
								else if((s[i] == '/')&&(s[i+1] == '/')){
									s.erase(i,i+n);
								}
								// remove single periods
								else if(s[i] == '.'){
									s.erase(i,1);
								}
								// remove single lines
								else if(s[n] == '\n'){
									cout << "blank line" << endl;
								}
							}
						}
						cout << s << endl;
					}
				}
				
				void printData(){
					vector <string>::iterator iter;
					for (iter = T.begin(); iter != T.end(); iter++){
    					cout << *iter << endl << endl;
					}
				}
				void printLineLength(){
					int counter = 1;
					vector <string>::iterator iter;
					for (iter = T.begin(); iter != T.end(); iter++){
						string temp = *iter;
						int y = temp.length();
						cout << counter << '\t' << y << endl;
					}
				}

};

int main(){

STRIP A;
A.readData();
//A.printLineLength();
A.cleanData();

return(0);
}

/* SAMPLE IO

*/
