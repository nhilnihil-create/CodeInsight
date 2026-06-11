#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
vector<int> a(1000100);
vector<int> cnt(1000100);

int main(){
    cin>>n;
    rep(i,n){
        cin>>a[i];
        cnt[a[i]]++;
        cnt[a[i]+1]++;
        if(a[i]>0) cnt[a[i]-1]++;
    }
    sort(cnt.begin(),cnt.end(),greater<int>());
    cout<<cnt[0]<<"\n";
    return 0;
}