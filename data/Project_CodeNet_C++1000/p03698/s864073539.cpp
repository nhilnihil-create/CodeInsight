#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  veci v(26,0);
  char x=1;
  while(x){
    x=0;
    cin>>x;
    if(v[x-97]){cout<<"no"<<endl;return 0;}
    v[x-97]=1;
  }
  cout<<"yes"<<endl;
}