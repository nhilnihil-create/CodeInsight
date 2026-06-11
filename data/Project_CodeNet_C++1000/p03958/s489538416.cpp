#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int k,t;
    cin>>k>>t;
    vector<int> a(t);
    rep(i,t) cin>>a[i];

    sort(all(a));
    cout<<max(0,a[t-1]-1-(k-a[t-1]))<<endl;  
}

