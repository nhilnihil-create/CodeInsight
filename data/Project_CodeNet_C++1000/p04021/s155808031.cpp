#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int main() {
    int N; cin>>N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    vector<int> ref=a;
    sort(ref.begin(),ref.end());
    int ans=0;
    for (int i = 0; i < N; ++i) {
        auto itr=lower_bound(ref.begin(),ref.end(),a[i]);
        int idx=itr-ref.begin();
        if((i&1)!=(idx&1)) ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}
