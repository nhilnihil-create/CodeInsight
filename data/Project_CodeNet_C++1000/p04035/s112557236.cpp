#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int inf = 1e8;
const ll INF = 1e18;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-9;
const long double pi = acos(-1.0);
using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1 -1};

int n;
ll m;
ll a[MAXN];
void solve() {
    cin >> n >> m;
    int ind = 0;
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> a[i];
        if (a[i] + a[i - 1] >= m){
            ind = i;
        }
    }
    if (ind == 0){
        cout << "Impossible";
        return;
    }
    cout << "Possible" << endl;
    for (int i = 1; i <= ind - 2; i++)
        cout << i << endl;
    for (int i = n - 1; i >= ind; i--) cout << i << endl;
    if (ind - 1 >= 1) cout << ind - 1 << endl;
}


int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(40);
    //freopen("inevit.in", "r", stdin);
    //freopen("inevit.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();


}