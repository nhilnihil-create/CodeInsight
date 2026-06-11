#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string s;
  	cin>>s;
  	rep(i,s.size()){
     	if(s[i]==',') s[i]=' ';
      	cout<<s[i];
    }
  	cout<<endl;
}