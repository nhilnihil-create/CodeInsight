#include<bits/stdc++.h>
#define int long long 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(a) a.begin(),a.end()
#define ld long double
#define ub upper_bound
#define lb lower_bound
#define pii pair<int,int>
using namespace std;
int mod = 1e9+7;
int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}
int power(int a,int b){
    int res = 1;
    while(b!=0){
        if(b&1)
            res = mul(res,a);
        b = b/2;
        a = mul(a,a);
    }
    return  res;
}
signed main(){
    fast;
    int n;
    cin>>n;
    int ans = 0;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    if(n%2 == 0){
        if(mp.find(0)!=mp.end()){
            cout<<0;
        }
        else{
            for(auto it:mp){
                if(it.second!=2){
                    cout<<0;
                    return 0;
                }
            }
            cout<<power(2,n/2);
        }
    }
    else{
        if(mp[0]!=1){
            cout<<0;
        }
        else{
            for(auto it:mp){
                if(it.first == 0)
                    continue;
                if(it.second!=2){
                    cout<<0;
                    return 0;
                }
            }
            cout<<power(2,n/2);
        }
    }
}
   
    