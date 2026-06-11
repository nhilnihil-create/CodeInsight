#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b;
	char aa;
	cin>>a>>aa>>b;
	if(aa=='+'){
		cout<<a+b;
	}
	else{
		cout<<a-b;
	}
	return 0;
}