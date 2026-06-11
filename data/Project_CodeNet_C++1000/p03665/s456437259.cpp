#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

ll rui(ll a, ll n){
    int x=a;
    while(n>1){
        a *=x;
        n--;
    }
    return a;
}

int main(){
    int N,P; cin>>N>>P;
    ll odd=0,even=0;
    
    rep(i,N){
        int x; cin>>x;
        if(x%2==0){
            even++;
        }else{
            odd++;
        }
    }
    
    // 1袋のとき
    if(N==1){
        if(P==1 && odd==1){
            cout << 1 << endl;
        }else if(P==1 && odd==0){
            cout << 0 << endl;
        }
        
        if(P==0 && even==1){
            cout << 1 << endl;
        }else if(P==0 && even==0){
            cout << 0 << endl;
        }
        return 0;
    }
    
    
    if(odd==0 && P==1){
        cout << 0 << endl; return 0;
    }
    if(odd==0 && P==0){
        cout << rui(2,even) << endl; return 0;
    }
    ll ans = rui(2,N-1);
    cout << ans << endl;
    
    /*
    ll ans=0;
    if(P==0){
        ans = pow(2,even)*(pow(2,odd)/2);
    }else if(P==1){
        ans = pow(2,even)*(pow(2,odd)/2);
    }
    
    cout << ans <<endl;
    */
}
