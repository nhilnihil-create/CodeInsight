#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define MAXN  1000005
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll v[305][305],n;
    cin>>n;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    bool flag=1;
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            flag=1;
            for(ll h=0;h<n;h++){
                if(h!=i&&h!=j){
                    if(v[i][j]>(v[i][h]+v[h][j])){
                        cout<<-1;
                        return 0;
                    }
                    if(v[i][j]==(v[i][h]+v[h][j])){
                        flag=0;
                    }
                }
            }
            if(flag)
                ans+=v[i][j];
        }
    }
    cout<<ans;


    return 0;
}

