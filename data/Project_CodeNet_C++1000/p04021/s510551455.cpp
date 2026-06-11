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
    vector <int> a(n), b(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) b[i] = a[i];
    
    sort(b.begin(), b.end());

    map <int, int> mp;
    for (int i = 0; i < n; i++) mp[b[i]] = i;
    vector <int> pos;
    for (int i = 0; i < n; i++){
        if (abs(mp[a[i]] - i) % 2) pos.pb(i);
    }
    
    cout << (int)pos.size() / 2 << endl;
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
