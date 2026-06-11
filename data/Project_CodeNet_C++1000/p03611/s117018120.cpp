
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n,ans=0;
    cin>>n;
    vi a(n),sum(100001,0);
    rep(i,n) cin>>a[i];
    sort(all(a));
    lli prev=a[0];
    lli cnt=0;
    rep(i,n){
        if(prev==a[i]) cnt++;
        else{
            sum[prev]=cnt;
            cnt=1;
            prev=a[i];
        }
        if(i==n-1){
            sum[prev]=cnt;
        }
    }
    if(sum.size()==1) ans=sum[0];
    else if(sum.size()==2) ans=sum[0]+sum[1];
    else{
    for(int i=1;i<sum.size()-2;i++){
        ans=max(ans,sum[i-1]+sum[i]+sum[i+1]);
    }
    }
    out(ans);
}