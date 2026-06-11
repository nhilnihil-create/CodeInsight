#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

typedef long long ll;

using namespace std;

const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;
const ll LINF = 1e18;
long long int n,cnt=0,ans=0,a[ohara],b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,k;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl,ok;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

bool okk(ll i){
        bool tmp;
        if(k<=a[i]){
          return true;
        }
        bitset<5000+10> dp;
        dp[0]=true;
        ok=true;
        rep(j,n){
          if(i==j)continue;
          dp|=(dp<<a[j]);
        }
        rrep(j,k-a[i],k){
          if(dp[j]){
            ok=false;
            break;
          }
        }
        if(!ok)tmp=true;
        else tmp=false;

        return tmp;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
      cin>>n>>k;
      rep(i,n)cin>>a[i];
      sort(a,a+n);
      ll le=0,ri=n-1,mid;
      while(ri-le>1){
        mid=(le+ri)/2;
        if(okk(mid)){
          ri=mid;
        }
        else{
          le=mid;
        }
        //cout<<le<<" "<<ri<<" "<<mid<<"\n";
      }
      //cout<<le<<" "<<ri<<" "<<mid<<"\n";
      if(!okk(ri))ans=ri+1;
      else if(!okk(le))ans=le+1;
      else ans=le;
      Cout(ans);
    
       
return 0;
}
