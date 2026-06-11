#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int t=a[i];
        if(a[t]==i) ans++;
    }
    cout<<ans/2<<endl;
}