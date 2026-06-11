#include <bits/stdc++.h>
#define arep(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinf(x,n) for(ll i=0;i<(n);i++)cin>>x[i];
#define coutf(x,n) for(ll i=0;i<(n);i++)cout<<x[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll cnt;

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(a==b&&a==c){
		cout << "1" << endl;
		return 0;
	}else if(a==b||a==c ||b==c){
		cout << "2" << endl;
		return 0;
	}else{
		cout << "3" << endl;
		return 0;
	}
}