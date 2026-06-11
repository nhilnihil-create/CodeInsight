#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string S;
  	cin>>S;
  	int count=0;
  	rep(i,S.size()-1){
     	 if(S[i]!=S[i+1]) count++;
    }
  	cout<<count<<endl;
}