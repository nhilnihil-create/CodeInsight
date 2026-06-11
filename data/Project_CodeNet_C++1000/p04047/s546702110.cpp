#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int INF = 1e8;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-9;
const long double pi = acos(-1.0);
using namespace std;
const ll MOD = 998244353;

int n;
int a[MAXN];
ll ans = 0;
void solve(){
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i += 2){
        ans += a[i];
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(17);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout)
    int step;
    step = 1;
    for (int i = 1; i <= step; i++)
        solve();

}