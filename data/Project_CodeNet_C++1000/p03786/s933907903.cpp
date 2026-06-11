#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

bool check(int mid){
    ll x = 0;
    for(int i = 0 ; i <= mid ; i++){
        x += a[i];
    }
    for(int i = mid + 1 ; i < n ; i++){
        if(a[i] <= 2 * x) x += a[i];
        else return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << n - l << endl;
}
