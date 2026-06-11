#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
#define ll long long
int main(){
	string S;
	cin >> S;
	size_t Ssize = S.size();
	string Sr;
	for(int i = 0; i < Ssize; i++){
		if(S[Ssize-i-1]=='b'){
			Sr +='d';
		}
		else if(S[Ssize-i-1] == 'd'){
			Sr += 'b';
		}
		else if(S[Ssize-i-1] == 'p'){
			Sr += 'q';
		}
		else{
			Sr += 'p';
		}
	}
	if(Sr.compare(S) == 0){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}