#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;

int n, ok;
LL a[N], L;

int main() {
	cin>>n>>L;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		if(i == 1) continue;
		if(a[i] + a[i - 1] >= L) ok = i - 1;
	} 
	if(!ok) cout<<"Impossible"<<endl;
	else {
		cout<<"Possible"<<endl;
		for(int i = 1; i < ok; i++)
			cout<<i<<endl;
		for(int i = n - 1; i > ok; i--)
			cout<<i<<endl;
		cout<<ok<<endl;
	}
	return 0;
}