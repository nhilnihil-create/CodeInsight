#include <bits/stdc++.h>
using namespace std;

int main() {
	string O, E;
	cin >> O >> E;
	string A;
	if (O.length()==E.length()){
	    for (int i=0; i<O.length(); i++){
	    A+=O.at(i);
	    A+=E.at(i);
	    }
	}
	else {
	    for (int i=0; i<E.length(); i++){
	    A+=O.at(i);
	    A+=E.at(i);
	    }
	    A+=O.at(O.length()-1);
	}
	cout << A << endl;
}
