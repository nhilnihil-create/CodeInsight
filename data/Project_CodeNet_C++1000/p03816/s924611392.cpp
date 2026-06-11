#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    int cnt=0;
    for(auto x:mp){
        if(x.second%2==0) cnt++;
    }
    if(cnt%2==0) cout << mp.size() << endl;
    else cout << mp.size()-1 << endl;
    
}