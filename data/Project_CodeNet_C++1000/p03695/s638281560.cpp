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
    vint cnt(9);
    for(auto a:A){
        if(a >= 1 && a<= 399){
            cnt[0]++;
        }else if(a >= 400 && a <= 799){
            cnt[1]++;
        }else if(a >= 800 && a <= 1199){
            cnt[2]++;
        }else if(a >= 1200 && a <= 1599){
            cnt[3]++;
        }else if(a >= 1600 && a <= 1999){
            cnt[4]++;
        }else if(a >= 2000 && a <= 2399){
            cnt[5]++;
        }else if(a >= 2400 && a <= 2799){
            cnt[6]++;
        }else if(a >= 2800 && a <= 3199){
            cnt[7]++;
        }else{
            cnt[8]++;
        }
    }
    int ans = 0;
    REP(i,8){
        if(cnt[i] != 0){
            ans++;
        }
    }
    if(ans == 0){
        cnt[8]--;
        ans = 1;
    }
    cout << ans << " ";
    ans += cnt[8];
    cout << ans << endl;
}