#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w;cin>>h>>w;
  lvector alph(26,0);
  string s;
  rep(i,h) {
    cin>>s;
    rep(j,w) alph[s[j]-'a']++;
  }
  ll g1=(h%2)*(w%2),g2=(h%2)*(w/2)+(w%2)*(h/2),g4=(h/2)*(w/2);
  rep(i,26) if(g1>0&&alph[i]%2==1) {alph[i]-=1;g1--;}
  rep(i,26) if(g2>0&&alph[i]%4==2) {alph[i]-=2;g2--;}
  g4+=g2/2;
  rep(i,26) if(g4>0&&alph[i]>0&&alph[i]%4==0) {g4-=alph[i]/4;alph[i]=0;} 
  puts((accumulate(ALL(alph),0)==0)?"Yes":"No");
  return 0;
}
