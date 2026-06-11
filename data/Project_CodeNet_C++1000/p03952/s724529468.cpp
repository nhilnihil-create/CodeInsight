#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin>>n>>x;
    ll ans[n*2];
    if(x==1 || x==2*n-1){
        cout<<"No"<<endl;
    }else{
        cout << "Yes"<<endl;
        if(n==2){
            for(int i=1;i<4;i++){
                cout << i<<endl;
            }
            return 0;
        }
        n--;
        if(x==2){
            ans[n-1]=3;
            ans[n]=2;
            ans[n+1]=1;
            ans[n+2]=4;
            ll index=5;
            for(int i=0;i<n-1;i++){
                ans[i]=index;
                index++;
            }
            for(int i=n+3;i<=2*n;i++){
                ans[i]=index;
                index++;
            }
        }
        else{
            ans[n]=x+1;
            ans[n+1]=x-1;
            ans[n-1]=x;
            ans[n-2]=x-2;
            
            vector<ll> v;
            for(int i=1;i<=2*n+1;i++){
                if(i<x-2||x+1<i){
                    v.pb(i);
                }
            }
            ll index=0;
            for(int i=0;i<n-2;i++){
                ans[i]=v[index];
                index++;
            }
            for(int i=n+2;i<=2*n;i++){
                ans[i]=v[index];
                index++;
            }
        }
        for(int i=0;i<=2*n;i++){
            cout << ans[i]<<endl;
        }
    }
    return 0;
}

