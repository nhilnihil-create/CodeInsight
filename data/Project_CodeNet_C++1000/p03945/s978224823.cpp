#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int col[2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin>>s;
    int n = s.size();
    int ans = 0;
    for(int i=1;i<n;i++){
        if(s[i-1]!=s[i]) ans++;
    }
    cout<<ans<<endl;


}