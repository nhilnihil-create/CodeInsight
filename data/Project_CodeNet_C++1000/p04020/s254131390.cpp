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
    vector <int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int kol = 0;
    for (int i = 0; i < n; i++){
        ans += a[i] / 2;
        if (a[i] == 0) kol = 0;
        if (a[i] % 2){
            kol++;
            ans += kol / 2;
            if (kol > 1) kol = 0;
        }
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
