#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
const int N = 3e3 + 10;
const ll mod = 1e9 + 7;
ll cnt[60][N];
int x[N];
signed main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
   string s;
   cin>>s;
   int l=s.length();
   int num=1<<(l-1);
   ll sum=0,tmp;
   rep(i,0,num-1){
       tmp=s[0]-'0';
       rep(j,0,l-1){
           if(j==l-1||i&(1<<j)){
               sum+=tmp;
               tmp=0;
               if(j==l-1)break;
           }
           tmp=tmp*10+s[j+1]-'0';
       }
   }
   pl(sum);
   return 0;
}