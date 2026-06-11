#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,l;cin >>n>>l;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    ll mx=0;ll k;
    for (int i = 0; i < n-1; ++i) {
        if(a[i]+a[i+1]>mx){
            mx=a[i]+a[i+1];
            k=i;
        }
    }
    if(mx<l){
        puts("Impossible");
        return 0;
    }
    vector<ll>ans;
    for (int i = k; i <n-1; ++i) {
        ans.push_back(i);
    }
    for (int i = k-1; i >=0; --i) {
        ans.push_back(i);
    }
    reverse(all(ans));
    puts("Possible");
    for (int i = 0; i < ans.size(); ++i) {
        cout <<ans[i]+1<<endl;
    }
    return 0;
}