#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;

bool Check(int n,int* a){
    for(int i=n;i>0;i-=2){
        if(i-1>0&&a[i]!=a[i-1]||i-2>0&&a[i]-a[i-2]!=2) return false;
    }
    return true;
}

ll Pow(ll n){
    ll ans=1LL,a=2LL;
    while(n){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}

void Solve(int n,int* a){
    sort(a+1,a+1+n);
    if(a[n]!=n-1||!Check(n,a)){
        cout<<0<<endl;
        return;
    }
    cout<<Pow((ll)(n>>1))<<endl;
}

int main(){
    int n;
    while(cin>>n){
        int a[100005];
        for(int i=1;i<=n;i++) cin>>a[i];
        Solve(n,a);
    }
    return 0;
}
