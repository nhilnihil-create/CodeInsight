#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
////////////////////////////////////////////////////////////

signed main() {
  string a,b,c;
  cin>>a>>b>>c;
  int as=0,bs=0,cs=0;
  int next=0;
  while(true){
    char ch;
    if(next==0){ch=a[as];as++;}
    else if(next==1){ch=b[bs];bs++;}
    else if(next==2){ch=c[cs];cs++;}
    if(as==a.size()&&ch=='a'){cout<<'A'<<endl;exit(0);}
    if(bs==b.size()&&ch=='b'){cout<<'B'<<endl;exit(0);}
    if(cs==c.size()&&ch=='c'){cout<<'C'<<endl;exit(0);}
    if(ch=='a')next=0;
    if(ch=='b')next=1;
    if(ch=='c')next=2;
  }
}
