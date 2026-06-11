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
    vector <ll> a(n), b(n);
    
    
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ll res = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--){
        a[i] += res;
        ll oc = a[i] % b[i];
        ll need = (b[i] - oc) % b[i];
        ans += need;
        res += need;
     }
     cout << ans << endl;
}       
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    //freopen("input.txt", "r", stdin);//freopen("output1.txt", "w", stdout);
    //freopen("icecream.in","r",stdin);// freopen("exam.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++){
         solve();
    }
}