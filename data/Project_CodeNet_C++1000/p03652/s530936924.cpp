#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(N,vector<int>(M));
    rep(i,N){
        rep(j,M){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    set<int> s;
    rep(i,M){
        s.insert(i);
    }
    int ans=N;
    vector<int> count(M);
    while(!s.empty()){
        rep(i,M){
            count[i]=0;
        }
        rep(i,N){
            rep(j,M){
                if (s.count(A[i][j])){
                    count[A[i][j]]++;
                    break;
                }
            }
        }
        int MAX=0,next;
        rep(i,M){
            if (chmax(MAX,count[i])){
                next=i;
            }
        }
        chmin(ans,MAX);
        s.erase(next);
    }
    cout << ans << endl;
}