#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,x;
bool used[200009];

int main(){
    cin>>n>>x;
    if(x==1||x==n*2-1){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    if(n==2){
        cout<<"1\n2\n3\n";
        return 0;
    }
    vector<ll>ans(2*n);
    ans[n]=x;
    used[x]=1;
    if(x==2){
        ans[n+1]=1;
        ans[n-1]=2*n-1;
        ans[n+2]=2*n-2;
        used[1]=used[2*n-1]=used[2*n-2]=1;
    }else{
        ans[n+1]=2*n-1;
        ans[n-1]=1;
        ans[n+2]=2;
        used[1]=used[2*n-1]=used[2]=1;
    }
    int x=1;
    FOR(i,1,2*n){
        if(ans[i])cout<<ans[i]<<endl;
        else{
            while(used[x])x++;
            cout<<x<<endl;
            used[x]=1;
        }
    }
}