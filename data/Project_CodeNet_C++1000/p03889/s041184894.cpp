#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;
	string T=S;
	for(int i=0; i<T.size(); ++i){
	    if(T[i]<'e'){
	        if(T[i]=='b') T[i] += 2;
	        else T[i] -= 2;
	    }else{
	        if(T[i]=='p') ++T[i];
	        else --T[i];
	    }
	}
	reverse(T.begin(), T.end());
	if(T==S) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
