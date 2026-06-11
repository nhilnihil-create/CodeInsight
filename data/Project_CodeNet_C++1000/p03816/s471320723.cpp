#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,d=0,sum=0;
    cin>>N;
    ll A[N];
    map<ll,ll> m;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        m[A[i]]++;
    }
    for(auto a:m) d+=a.second-1;
    if(d==N) cout<<"1"<<endl;
    else cout<<N-d-d%2<<endl;
}