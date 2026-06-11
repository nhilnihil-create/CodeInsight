#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define REVERSE(x) reverse((x).begin(), (x).end())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << '\n'
#define endl '\n'

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-10;

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<typename T>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

bool solve(void){
    int n;
    cin >> n;

    vector<int> a(n);
    int mini = n;
    int maxi = 0;
    rep(i, n){
        cin >> a[i];
        chmin(mini, a[i]);
        chmax(maxi, a[i]);
    }

    if(maxi - mini > 1){
        return false;
    }

    if(maxi == mini){
        return a[0] * 2 <= n || a[0] == n - 1;
    }

    int k = maxi;
    int uni = 0;
    rep(i, n){
        uni += a[i] == k - 1;
    }

    return uni < k && uni + (n - uni) / 2 >= k;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    if(solve()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    cout << flush;

    return 0;
}