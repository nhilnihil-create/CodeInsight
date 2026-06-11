#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	string ss="";
	for (int i=S.length()-1; i>=0; i--){
	    ss+=S[i];
	    if (ss=="resare") ss="";
	    else if (ss=="esare") ss="";
	    else if (ss=="maerd") ss="";
	    else if (ss=="remaerd") ss="";
	}
	if (ss=="") cout << "YES" << endl;
	else cout << "NO" << endl;
}
