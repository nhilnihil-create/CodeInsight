#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> A(n+1, 0);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=1; i<=n-1; i++){
        if(A[i]%2==1){
            if(A[i+1]!=0){
                A[i]--;
                A[i+1]--;
                ans++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        ans += A[i]/2;
    }
    cout<<ans<<endl;
}