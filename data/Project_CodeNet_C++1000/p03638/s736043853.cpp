#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int h,w,n;
    cin >> h >> w >> n;
    priority_queue<int,vector<int>,greater<int>> que;
    rep(i,n){
        int a;cin >> a;
        rep(j,a)que.push(i+1);
    }
    rep(i,h){
        if(!(i%2)){
            for (int j = 0; j < w; ++j){
                int o = que.top();
                cout << o << " ";
                que.pop();
            }
            cout << endl;
        }else{
            vector<int> out;
            for (int j = w; j > 0; --j){
                out.push_back(que.top());
                que.pop();
            }
            reverse(out.begin(),out.end());
            for(int o : out)cout << o << " ";
            cout << endl;
        }
    }
    return 0;
}