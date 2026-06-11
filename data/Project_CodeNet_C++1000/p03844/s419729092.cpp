#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	char op;
	cin>>a>>op>>b;
	if(op=='+') cout<<a+b<<endl;
	else cout<<a-b<<endl;
	return 0;
}
