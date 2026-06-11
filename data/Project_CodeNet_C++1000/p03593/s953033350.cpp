#include<bits/stdc++.h>
using namespace std;

int main() {
	int H,W; cin>>H>>W;
	vector<int> a(26,0);
	char ch;
	for (int i=0; i<H*W; i++)
		cin>>ch, a[ch-'a']++;
	int one=0,two=0;
	for (int x:a) {
		if(x%4) two++;
		if(x%2) one++;
	}
	int two_max=((H%2)*W+(W%2)*H)/2;
	cout<<(one<=1&&two<=two_max?"Yes":"No")<<"\n";
	return 0;
}