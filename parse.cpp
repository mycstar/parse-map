#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main (int argc, char* argv[])
{

ifstream IN;
ofstream OUT;
string line;
int count=0;
map<string, int> ID;

IN.open (argv[1]);
while ((!IN.eof()) && IN.good()){
	getline(IN,line);
	ID[line]=1;
	count++;
}

cout<<"number of IDs"<< count<<endl;
IN.close();
IN.clear();

map <string,int>::iterator it;


count=0;

for (it=ID.begin(); it!=ID.end(); it++)
{
 count++;
}
cout<<"number of records in map"<< count<<endl; 


count=0;
IN.open (argv[2]);
OUT.open (argv[3]);
while ((!IN.eof()) && IN.good())
{
	getline (IN, line);
	if (line[0]=='@') {
		int pos =line.find_first_of(' ');
		string temp_id=line.substr(1, pos-1);
		//cout << temp_id;
		//return 0;
		if (ID.find(temp_id)!=ID.end()){
			OUT<<line<<endl;
			//cout<<line<<endl;
			getline(IN,line);
			OUT<<line<<endl;
			getline(IN,line);
			OUT<<line<<endl;
			getline(IN,line);
			OUT<<line<<endl;
			count++;
			//return 0;
		}	
	}
}
		
IN.close();
IN.clear();
OUT.close();
OUT.clear();
cout<<"total records output"<< count<<endl;

return 0;

}


