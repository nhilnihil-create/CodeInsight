#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

template<typename T>
bool chmax(T &a, T b){
    if(a < b){
        a = b;
        return true;
    }else{
        return false;
    }
}

bool solve(void){
    int n;
    cin >> n;

    vector<int> cnt(n);
    int maxi = -1;
    rep(i, n){
        int a;
        cin >> a;
        ++cnt[a];
        chmax(maxi, a);
    }

    if(maxi % 2 == 0){
        REP(i, maxi / 2 + 1, maxi + 1){
            if(cnt[i] < 2){
                return false;
            }
        }
        if(cnt[maxi / 2] != 1){
            return false;
        }
        rep(i, maxi / 2){
            if(cnt[i] > 0){
                return false;
            }
        }
    }else{
        REP(i, maxi / 2 + 2, maxi + 1){
            if(cnt[i] < 2){
                return false;
            }
        }
        if(cnt[maxi / 2 + 1] != 2){
            return false;
        }
        rep(i, maxi / 2 + 1){
            if(cnt[i] > 0){
                return false;
            }
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    if(solve()){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}