
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
typedef long long ll;
//typedef pair<ll,ll> P;

using namespace std;


int main(){
  string s;
  cin>>s;
  int a=s.size();
  if (s[0]==s[a-1])a++;
  a%=2;
  if (a==0)cout<<"Second";
  if (a==1)cout<<"First";

}
