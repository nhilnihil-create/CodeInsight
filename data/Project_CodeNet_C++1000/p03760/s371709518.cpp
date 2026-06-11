#include <bits/stdc++.h>
using namespace std;
string o,e;
int numo=0,nume=0;
int main() {
cin>>o>>e;
for(int i=0;i<o.length()+e.length();i++) {
	if(i%2==0) {
		cout<<o[numo++];
	} else {
		cout<<e[nume++];
	}
}
}
