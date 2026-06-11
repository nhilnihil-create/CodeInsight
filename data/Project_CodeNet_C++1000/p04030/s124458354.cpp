#include <iostream>
#include <string>


using namespace std;

int main(int argc, char** argv) {
	string name,num;
	cin>>name;
	
	for(int i=0;i<name.length();i++)
	{
		if(name[i]=='0')
		 num.push_back('0');
		else if(name[i]=='1')
		 num.push_back('1');
		else if(name[i]='B'&& num.empty()!=true)
		 num.pop_back();
		 
	}
	cout<<num<<endl;
	
	return 0;
}