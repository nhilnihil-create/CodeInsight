#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll x,cnt;
    cin>>x;
    cnt=x/11*2; x%=11;
    if(x>0&&x<=6) cnt++;
    else if(x>6&&x<=10) cnt+=2;
    cout<<cnt<<endl;
    return 0;
}