#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  vector<int> d(26,0);
  
  int n = s.size();
  rep(i,n){
    if(d[s[i] - 'a'] == 1){
      cout<<"no"<<endl;
      return 0;
    }
    d[s[i] - 'a'] = 1;
  }
  cout<<"yes"<<endl;
}