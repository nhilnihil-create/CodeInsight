#include<iostream>
#include<string>
using namespace std;

int main(){
	bool N=false;
	bool S=false;
	bool E=false;
	bool W=false;
	string schedule;
	cin >> schedule;
	for(const char& c : schedule){
		switch(c){
		case 'N':N=true;break;
		case 'S':S=true;break;
		case 'E':E=true;break;
		case 'W':W=true;break;
		}
	}
	if(N==S && E==W){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
