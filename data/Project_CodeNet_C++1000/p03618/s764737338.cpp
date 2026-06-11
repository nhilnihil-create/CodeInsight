#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
#define MOD 1000000007
#define B2 100000007
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
#define P pair<int,int>
ll n,a,ans = 0,c,x,y,t;
string s;
int main() {
    cin >> s; vector<ll> al(26,0);
    n = s.size();
    rep(i, s.size()) {
        al[s[i] - 'a']++;
    }rep(i, 26) {
        ans += al[i] * (al[i] - 1) / 2;
    }cout << n * (n - 1) / 2 - ans + 1 << endl;
}