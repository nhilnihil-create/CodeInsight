#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int k,t;
    cin>>k>>t;
    vector<int> a(t);
    rep(i,t) cin>>a[i];
    sort(all(a));
    if(k-a[t-1]>=a[t-1]-1) cout<<0<<endl;
    else{
        cout<<a[t-1]-1-(k-a[t-1])<<endl;
    }
}

