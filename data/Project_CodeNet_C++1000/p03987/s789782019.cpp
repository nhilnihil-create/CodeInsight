#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
const double pi = acos(-1.0);
const double eps = 1e-9;
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n), l(n, - 1), r(n, - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector <int> pos;
    for (int i = 0; i < n; i++){
        while (!pos.empty() && a[pos.back()] >= a[i]) pos.pop_back();
        if (pos.size() == 0) l[i] = 0;
        else l[i] = pos.back() + 1;
        pos.pb(i);
    }
    pos.clear();
    for (int i = n - 1; i >= 0; i--){
        while (!pos.empty() && a[pos.back()] >= a[i]) pos.pop_back();
        if (pos.size() == 0) r[i] = n - 1;
        else r[i] = pos.back() - 1;
        pos.pb(i);
    }
    //for (int i = 0; i < n; i++) cout << l[i] + 1 << " " << i + 1 << " " << r[i] + 1 << endl;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += (r[i] - i + 1) * 1ll * (i - l[i] + 1) * 1ll * a[i];
    }
    cout << ans << endl;
}   
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(10);
    //freopen("input.txt", "r", stdin);//freopen("output1.txt", "w", stdout);
    //freopen("icecream.in","r",stdin);// freopen("exam.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++){
         solve();
    }
}
