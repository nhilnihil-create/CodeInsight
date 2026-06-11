#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string S;
  	cin>>S;
  	int count[26]={0};
  	bool flag=false;
  	rep(i,S.size()) count[S[i]-97]++;
  
  	rep(i,26){
     	if(count[i]==0){
        	cout<<char('a'+i)<<endl;
          	flag=true;
          	break;
        }
      	
    }
  
  	if(!flag) cout<<"None"<<endl;
  
}