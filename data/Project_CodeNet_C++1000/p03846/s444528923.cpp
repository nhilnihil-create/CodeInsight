#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll N; cin>>N;
    vector<ll>a(N);
    map<ll,ll>mp;
    rep(i,N){
        cin>>a[i];
        mp[a[i]]++;
    }

    bool oks =true;
    if(N%2!=0)oks=false;
    for(auto p:mp){
        if(oks){
            if(p.first%2==0||p.first>=N||p.second!=2){
                cout<<0<<endl;
                return 0;
            }
        }
        else{
                  if(p.first==0&&p.second!=1){
                    cout<<0<<endl;
                    return 0;
                }
            else if(p.first%2!=0||p.first>=N&&p.second!=2){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    ll ans =1;
    rep(i,N/2){
        ans*=2;
        ans%=mod;
    }
    cout<<ans<<endl;
}


