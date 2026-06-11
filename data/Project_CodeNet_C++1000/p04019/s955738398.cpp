#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define RREP(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define REP2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;
using namespace std;



int main(){
	string s; cin>>s;
    ll n = s.size();
    ll N = 0,E = 0,W = 0,S = 0;
	REP(i,n){
      if(s[i] =='N')N++;
      if(s[i] =='E')E++;
      if(s[i] =='W')W++;
      if(s[i] =='S')S++;
    }
    bool flg = true;
  	if(N==0 && S!=0) flg = false;
    if(S==0 && N!=0) flg = false;
    if(E==0 && W!=0) flg = false;
    if(W==0 && E!=0) flg = false;
  
    if(flg) cout << "Yes";
    else cout << "No";

  	return 0;
}
