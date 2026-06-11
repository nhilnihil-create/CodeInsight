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
    cin >> N;
    vint A(N);
    cin >> A;
    int ans = 0;
    for(auto a:A){
        ans += a;
    }
    if(0 != ans%10){
        cout << ans << endl;
        return 0;
    }
    sort(A.begin(),A.end());
    for(auto a:A){
        if(0 == a%10)continue;
        ans -= a;
        if(0!=ans%10){
            cout << ans << endl;
            return 0;
        }
    }
    cout << 0 << endl;

}