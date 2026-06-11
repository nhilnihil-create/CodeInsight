#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;



int main(void){
    ll k;
    cin>>k;
    if(k==0){
        cout<<2<<endl;
        cout<<0<<" "<<0<<" "<<endl;
        return 0;
    }
    if(k==1){
        cout<<2<<endl;
        cout<<0<<" "<<2<<endl;
        return 0;
    }
    if(k<=50){
        cout<<k<<endl;
        for(ll i=1;i<=k;i++){
            if(i==k)cout<<i<<endl;
            else cout<<i<<" ";
        }
    }
    else{
        cout<<50<<endl;
        vector<ll>ans(50);
        k-=50;
        ll num=0;
        if(k>=50)num=k/50,k = k-num*50;
        for(ll i=0;i<50;i++)ans[i]=i+1+num;
        for(ll j=0;j<k;j++)ans[49-j]++;
        for(ll i=0;i<50;i++){
            if(i==49)cout<<ans[i]<<endl;
            else cout<<ans[i]<<" ";
        }
    }
    return 0;
}