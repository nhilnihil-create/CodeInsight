#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7; 
int mod_fact(int n,int p){
	if(n>=p)return 0;
	if(n<0)return -1;
	long long res=1;
	for (int i =1; i <= n; i++){
		res=(res*i)%p;
	}
	return int(res);
}

int main(void)
{
	int n;
	int a[100005];
	cin>>n;
	for (int i = 1; i <= n; i++){
		cin>>a[i];
	}
	ll res=1;
	stack<int> st;
	for (int i = 1; i <= n; i++){
		st.push(a[i]);
		if(a[i]<2*st.size()-1){
			res=(res*st.size())%mod;
			st.pop();
		}
	}
	res=(res*ll(mod_fact(st.size(),mod)))%mod;
	cout<<res<<endl;
	return 0;
}
