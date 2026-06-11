#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string::iterator it;
	int a[26] = {0};
	for(it = s.begin(); it<s.end(); it++){
		a[*it-97]++;
	}
	
	for(int i=0;i<26;i++){
		if(a[i]>1){
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;
}