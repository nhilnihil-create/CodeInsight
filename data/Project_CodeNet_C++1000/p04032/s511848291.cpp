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
  char a,b;
  a=s[0],b=s[1];
  bool ok=false;
  if(a==b)ok=1;
  ll p=1,q=2;
  for(ll i=2;i<s.size();i++){
    char c=s[i];
    if(b==c){
      ok=1;
      p=i;
      q=i+1;
      break;
    }
    if(a==c){
      ok=1;
      p=i-1;
      q=i+1;
      break;
    }
    a=b;
    b=c;
  }

  if(!ok)cout << -1 << " " << -1 << endl;
  else cout << p << " " << q << endl;

}