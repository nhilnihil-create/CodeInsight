#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  string s;
  cin >> s;

  vec a;

  for(ll i=0;i<s.size();i++){
    if(s[i]=='0')a.push_back(0);
    else if(s[i]=='1')a.push_back(1);
    else if(a.size()!=0) a.pop_back();
//    for(ll j=0;j<a.size();j++)cout << a[j] << endl;
  }

  for(ll i=0;i<a.size();i++)cout << a[i] ;

}