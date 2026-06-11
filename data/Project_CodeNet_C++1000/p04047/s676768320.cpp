#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define M 1000000007
#define fors(i,n) for(int i=0;i<n;++i)
#define fore(i,a,b) for(int i=a;i<=b;++i)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vv vector<int>
#define endl "\n"
#define test(i) cout<<i<<endl
#define itrt int t; cin>>t; fors(i,t)
#define itr1 int t; cin>>t;
#define ff first
#define ss second
#define pb push_back
#define vmp make_pair
#define ppb pop_back
#define sorta(a,n) sort(arr,arr+n)
#define sortv(x) sort(x.begin(),x.end())
void file(){
    #ifdef LOCAL
    freopen("demo.in","r",stdin);
    freopen("demo.out","w",stdout);
    #endif
}
int main(){
    fastio;
    file();
    int t;
    cin>>t;
    vv v(t*2);
    for(int i=0;i<2*t;++i){
      cin>>v[i];
    }
    sortv(v);
    int sum=0;
    for(int i=0;i<2*t-1;i=i+2){
      sum+=min(v[i],v[i+1]);
    }
    test(sum);
}
// 5
// 100 1 2 3 14 15 58 58 58 29