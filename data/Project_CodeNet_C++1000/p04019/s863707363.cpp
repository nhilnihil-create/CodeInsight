#include<bits/stdc++.h>
using namespace std;

string s;
int n;
bool d[4];

int main() {
	cin>>s;
	n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] == 'N') d[0] = 1;
		if(s[i] == 'W') d[1] = 1;
		if(s[i] == 'S') d[2] = 1;
		if(s[i] == 'E') d[3] = 1; 
 	}
 	if(d[0] != d[2] || d[1] != d[3]) cout<<"No"<<endl;
 	else cout<<"Yes"<<endl;
	return 0;
}