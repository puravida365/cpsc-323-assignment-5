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

using namespace std;

class STRIP{
		private:
				fstream f;
				vector <string> T;
				vector <string> X;
				vector <string>::iterator iter;
				string line;
				string s;
				int n, counter;
		public:
				void readData(){
					f.open("data.txt", ios::in);
					if(!f){
						cout << "File not found";
					}
					while(getline(f, line)){
						if(!line.empty()){
							T.push_back(line);
						}
						else{
							// do nothing
						}
					}
					// hack to remove empty lines
					T.erase (T.begin()+2);
					T.erase (T.begin()+5);
					T.erase (T.begin()+7);
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
								// remove single lines
								else if(s[n] == '\n'){
									cout << "blank line" << endl;
								}
							}
						}
						cout << s << endl;
					}
					
				}
};

int main(){

	STRIP A;
	A.readData();
	A.cleanData();

	return(0);
}

/* SAMPLE IO
int main()
{
 int x,y;
 cout<< "Enter two numbers:";
 cin>>x>>y;
 int total = x + y;
 float average = total / 2.;
 return 0;
}
*/
