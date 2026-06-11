#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int INF = 1e8;
const int MAXN = 2e6 + 200;
const  long double eps = 1e-16;
const long double pi = acos(-1.0);
using namespace std;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int n, m;
vector <int> a[2];
vector <int> ans;
void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[x & 1].pb(x);
    }
    if (a[1].size() > 2){
        cout << "Impossible\n";
        return;
    }
        if (a[1].size() >= 1) ans.pb(a[1][0]);
        for (auto x : a[0]) ans.pb(x);
        if (a[1].size() > 1)
            ans.pb(a[1][1]);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
       
        if (n == 1 && ans[0] != 1){
            ans[0]--;
            ans.pb(1);
        }
        else{
            ans[0]++;
            ans[ans.size() - 1]--;
            if (ans[ans.size() - 1] == 0) ans.pop_back();
        }
        cout << ans.size() << endl;
        for (auto x : ans) cout << x  << " ";
}
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(7);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout)
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();

}