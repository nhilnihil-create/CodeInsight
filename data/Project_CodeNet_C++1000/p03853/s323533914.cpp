#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w;
	
	cin >> h >> w;
	vector< vector<char> > c(h,vector<char>(w));
	for(int i=0; i<h; i++){
	string s;
		for(int j=0; j<w; j++){
			char temp;
			cin >> temp;
			s += temp;
			
		}
		cout << s << endl << s << endl;
	}

 }
