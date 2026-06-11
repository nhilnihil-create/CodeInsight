#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;
typedef long long ll;

const int N=55;
ll ans[N];
void solve(){
    ll k;
    scanf("%lld",&k);
    int n=50;
    for(int i=1;i<=n;i++) ans[i]=n-1;
    for(int i=1;i<=n;i++){
        ll cnt=k/n;
        if(i<=k%n) cnt++;
        ans[i]+=cnt*n-(k-cnt);
    }
    printf("50\n");
    for(int i=1;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
}

int fuck(){
    int id=1;
    for(int i=2;i<=50;i++){
        if(ans[i]>ans[id]) id=i;
    }
    return id;
}

int main(){
    solve();
    /*
    ll cnt=0;
    multiset<ll>st;
    int n=50;
    while(ans[fuck()]>=n){
        int id=fuck();
        for(int i=1;i<=n;i++){
            if(i!=id) ans[i]++;
        }
        ans[id]-=n;
        cnt++;
    }
    cout<<cnt<<endl;
    */
}
