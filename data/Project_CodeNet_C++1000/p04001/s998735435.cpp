#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const long long MOD = 998244353;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll = long long;
using pLL = std::pair<ll, ll>;
#define SORT(v) std::sort(v.begin(), v.end())
#define RSORT(v) std::sort(v.rbegin(), v.rend())
constexpr auto PI = 3.14159265358979323846264338327950L;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    long long ans=0;
    int N = (int)S.size();
    for(int bit=0;bit<(1<<(N-1));++bit){
        long long sum = 0;
        long long a = S[0] - '0';
        for(int j=0; j<N-1;++j){
            if(bit&(1<<j)){
                sum+=a;
                a=0;
            }
            a=a*10+S[j+1]-'0';
        }
        sum +=a;
        ans+=sum;
    }
    cout << ans <<endl;
    return 0;
}
