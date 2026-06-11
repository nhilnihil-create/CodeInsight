#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int a,b,c;
  	cin>>a>>b>>c;
  	int kind=3;
  	if(a==b || b==c) kind--;
  	if(a==c) kind--;
  	cout<<kind<<endl;
}