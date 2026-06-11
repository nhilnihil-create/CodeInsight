#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void){
	string s;
	cin>>s;
	char lst = 0;
	int changes = 0;
	for (auto i:s){
		if(lst != i){
			changes++;
			lst = i;
		}
	}
	cout<<changes-1;
	return 0;
}
