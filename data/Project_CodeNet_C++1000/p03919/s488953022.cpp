#include <bits/stdc++.h>
using namespace std;

int main() {
	int H,W;
	cin>>H>>W;
	string e="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0;i<H;i++) {
		for(int j=0;j<W;j++) {
			string s;
			cin>>s;
			if(s=="snuke") {
				cout<<e.at(j)<<i+1<<endl;
				break;
			}
		}
	}
}
