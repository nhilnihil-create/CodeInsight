#include <bits/stdc++.h>
using namespace std;
string s;
int pos , sums , sumt;
int main(){
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'T'){
			if(sums == 0){
				sumt++;
			}
			else sums--;
		}
		if(s[i] == 'S'){
			sums++;
		}
	}
	cout << sums + sumt << endl;
}