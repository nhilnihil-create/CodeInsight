#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
int t[110], v[110];
int lm[202020];
int n, T;

int main(){
    LL x, y;
    cin >> x >> y;
    cout << (abs(x-y) <= 1 ? "Brown" : "Alice") << endl;
}