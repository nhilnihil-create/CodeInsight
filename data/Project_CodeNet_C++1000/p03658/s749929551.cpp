#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef long double ld;
typedef long long int ll;
const ll INF = (1LL << 63);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0; i < n;i++)
const int MAX = 1000000010;
const ll MOD = 1000000007;
int n, m,k,sum = 0; string s;
int main() {
    cin >> n >> k; vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    rep(i, k) {
        sum += a[i];
    }cout << sum << endl;
}