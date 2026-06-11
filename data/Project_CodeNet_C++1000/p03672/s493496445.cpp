#include <bits/stdc++.h>
using namespace std;

bool check(string x){
    if (x.length()%2==1) return false;
    if (x.substr(0, x.length()/2)!=x.substr(x.length()/2)){
        return false;
    }
    return true;
}

int main() {
	string S;
	cin >> S;
	for (int i=S.length()-1; ; i--){
	    if (check(S.substr(0,i))) {
	        cout << i<< endl;
	        return 0;
	    }
	}
}