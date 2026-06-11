#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int N;
    string S,T;
    cin >> N >> S >> T;
    int ans = 0;
    REP(i,N){
        if(S[i] == T[0]){
            string s = S.substr(i,N-i);
            string t = T.substr(0,N-i);
            if(s == t){
                chmax(ans,N-i);
            }
        }
    }
    cout << (2*N-ans) << endl;
}