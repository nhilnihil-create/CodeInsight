#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int a,b,c,d;
  	cin>>a>>b>>c>>d;
  	if(a==b) cout<<"Draw"<<endl;
  	else if(a==1) cout<<"Alice"<<endl;
  	else if(b==1) cout<<"Bob"<<endl;
  	else if(a<b) cout<<"Bob"<<endl;
  	else cout<<"Alice"<<endl;
}