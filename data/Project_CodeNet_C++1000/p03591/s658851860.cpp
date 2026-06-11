#include <iostream>
#include <string>
using namespace std;

int main() {
	string S; cin >> S;
	string T="YAKI";
	bool torichan=true;
	if(S.size()<4) torichan=false;
	else{
	    for(int i=0; i<4; ++i){
	        if(S[i]!=T[i]){
	            torichan=false;
	            break;
	        }
	    }
	}
	if(torichan) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
