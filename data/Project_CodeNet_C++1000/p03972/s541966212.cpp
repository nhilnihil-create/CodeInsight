#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
const double pi = acos(-1.0);
const double eps = 1e-6;
using namespace std;


const int N = 1e5 + 1;
int n, m;
ll p[N], q[N], pref[N];
void solve(){ 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= m; i++)
        cin >> q[i];
    
    ll sum = 0;

    for (int i = 1; i <= n; i++) sum += p[i];
    for (int i = 1; i <= m; i++) sum += q[i];

    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] += pref[i - 1] + p[i];

    for (int i = 1; i <= m; i++){
        int pos = upper_bound(p + 1, p + n + 1, q[i]) - p;
        //cout << pos << endl;
        sum += pref[pos - 1] + (n - pos + 1) * 1ll * q[i]; 
    }
    cout << sum << endl;
}       
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(5);
    //freopen("input.txt", "r", stdin);//freopen("output1.txt", "w", stdout);
    //freopen("icecream.in","r",stdin);// freopen("exam.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++){
         solve();
    }
}