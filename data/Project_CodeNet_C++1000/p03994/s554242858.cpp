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
    string s; cin>>s;
    int k; cin>>k;
    int cnta = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == 'a') {
            cnta++;
            continue;
        }
        int t = 'z'-c+1;
        if(k>=t){
            k-=t;
            s[i]='a';
            cnta++;
        }
    }
    if(cnta == n || k>0){
        // 残り=kぶんだけ最後を回す
        char c = s[n-1]+(k%26);
        s[n-1] = c;
        cout<<s<<endl;
        return 0;
    }
    cout<<s<<endl;
}