#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    if(x==1||x==2*n-1) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        n=2*n-1;
        vector<int> ans(n);
        ans[n/2-1]=x-1;
        ans[n/2]=x;
        ans[n/2+1]=x+1;
        
        int now=1;
        rep(i,0,n){
            if(n/2-1<=i && i<=n/2+1) continue;
            while(x-1<=now && now<=x+1) now++;
            ans[i]=now;
            now++;
        }
        rep(i,0,n) cout<<ans[i]<<endl;
    }
}
