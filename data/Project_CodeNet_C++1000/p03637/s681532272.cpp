#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,a,cnt2=0,cnt4=0;
    cin>>n;
    rep(i,n){
        cin>>a;
        if(a%4==0) cnt4++;
        else if(a%2==0) cnt2++;
    }
    cout<<(2*cnt4+max(cnt2-1,(ll)0)>=n-1?"Yes":"No")<<endl;
    return 0;
}