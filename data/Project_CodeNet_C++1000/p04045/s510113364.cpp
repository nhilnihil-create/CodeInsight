#include<bits/stdc++.h>
using namespace std;
#define N (int)(1e5+7)
#define inf (int)(1e9+7)
#define INF (long long) (1e18+7)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int M = (int)(2e6 + 239);

int d[13];

bool f(int n){
    while(n>0){
        if(d[n%10])return false;
        n/=10;
    }
    return true;
}

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=10;i++)d[i]=0;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        d[x]=1;
    }
    for(int i=n;i<=10*n+3;i++){
        if(f(i)){
            cout<<i<<'\n';
            break;
        }
    }
    return;
}
int main(){
    fastio;
    solve();
    return 0;
}