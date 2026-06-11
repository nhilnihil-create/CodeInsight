#include <bits/stdc++.h>
#include<utility>
#include<algorithm>

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define INF 1e9+7
#define PI 3.141592653
#define inf 200007
#define P pair<ll,ll>

using namespace std;
int n;
ll k;
vl a;

int main(){
    string ans;
    cin>>n>>k;
    pan(i,n){
        ll x;
        cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    ll x=a[0],m=a[n-1];
    if(k>m) ans="IMPOSSIBLE";
    else{
        pans(i,n,1){
            if(a[i]==k){
                ans="POSSIBLE";
                break;
            }
            if(a[i]%x!=0){
                ll g=a[i]/x,z=a[i]%x;
                while(g--){
                    if((g*(x)+z)<x){
                        x=g*(x)+z;
                        break;
                    }
                }
                if(g==0) x=z;
            }
        }
        if(k%x==0) ans="POSSIBLE";
        else ans="IMPOSSIBLE";
    }
    cout<<ans;
}   