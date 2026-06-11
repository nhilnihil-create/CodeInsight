#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  ll a,b,c,fa,fb,fc,cnt=0;
  cin>>fa>>fb>>fc;
  if((fa%2+fb%2+fc%2)!=0){cout<<0<<endl;return 0;}
  while(!(a%2+b%2+c%2)&&cnt<400000007){
    a=fb/2+fc/2;
    b=fa/2+fc/2;
    c=fa/2+fb/2;
    fa=a;
    fb=b;
    fc=c;
    cnt++;
  }
  if(cnt==400000007)cout<<-1<<endl;
  else cout<<cnt<<endl;
}