#define SORT(v) sort(v.begin(), v.end())
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <numeric>

// #include "ane.cpp"

#define INF (int)1e9
#define LLINF (long long)1e18
#define NMAX 8
#define MMAX 200
#define MOD (long long)(1e9+7)
using namespace std;

// コメントアウトするとdb_printf()を実行しない
// #define DEBUG
// デバッグ用printf
void db_printf(const char* format, ...){
    #ifndef DEBUG
    return;
    #endif
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);  // コンソールに出力
    va_end(arg);
}
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
typedef pair<int, int> p;
typedef long long ll;

ll N,M,K,A,B,C,D,E;
int dp[NMAX][MMAX] = {};
std::vector<int> x, v;

static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

ll ans = 1LL;

bool canMakeSpace(std::vector<int> V, int i){
    // check first i toads can make space for xx[i]
    // for (int j = 0; j < V.size(); ++j)
    // {
    //     cout << V[j] << " ";
    // }
    // cout << endl;
    for (int ii = 0; ii < i; ++ii)
    {
        if (V[ii] < 2 * ii)
        {
            // cout << "failure.\n";
            return false;
        }
    }
    return true;
}

void solve(){
    // 解答アルゴリズム
    std::vector<int> interval;
    for (int i = 0; i < x.size()-1; ++i)
    {
        interval.push_back(x[i+1] - x[i]);
    }
    do
    {
        db_printf("seq: ");
        for(auto vv: v){
            db_printf("%d ", vv);
        }
        db_printf("\n");

        std::vector<int> xx = x;
        bool failed = false;

        for(auto vv: v){
            int index = distance(xx.begin(), find(xx.begin(), xx.end(), x[vv]));
            if (canMakeSpace(xx, index))
            {
                // toad vv can reach goal
                xx.erase(xx.begin() + index);
            }else
            {
                // db_printf("failed\n");
                failed = true;
                break;
            }
        }
        if (!failed)
        {
            ans++;
        }
    } while (next_permutation(v.begin(), v.end()));

}
void debug(){
    // デバッグ用出力
}
void answer(){
    // 解答出力
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    // 入力の読み込み，番兵法
    // ios::sync_with_stdio(false);

    Fill(dp, -1);

    scanf("%lld", &N);
    std::vector<int> v;
    int k=0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
        k++;
        if (x < 2*k - 1)
        {
            // printf("delete k=%d\n", k);
            ans = ans * k % MOD;
            k--;
            v.erase(v.begin() + k);
        }
    }
    for (int i = 1; i <= v.size(); ++i)
    {
        ans = ans * i % MOD;
    }
    answer();

    return 0;
}