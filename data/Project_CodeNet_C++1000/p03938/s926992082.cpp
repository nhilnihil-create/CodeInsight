#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    p.resize(n);
    for(auto &i : p) cin >> i;
    vector <int> v(n);
    for(int i = 0 ; i < n ; i++){
        p[i]--;
        v[p[i]] = i;
    }
    vector <int> a(n), b(n);
    b[0] = v[0];
    for(int i = 1 ; i < n ; i++){
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        if(v[i] > a[i] + b[i]) a[i] = v[i] - b[i];
        else b[i] = v[i] - a[i];
        while(a[i] == a[i - 1] || b[i] == b[i - 1]){
            a[i]++;
            b[i]--;
        }
    }
    int mn = 1e9;
    for(int i = 0 ; i < n ; i++){
        mn = min(mn, min(a[i], b[i]));
    }
    for(int i = 0 ; i < n ; i++){
        a[i] += -mn + 1;
        b[i] += -mn + 1;
    }
    for(auto &i : a) cout << i << " ";
    cout << endl;
    for(auto &i : b) cout << i << " ";
    cout << endl;
}
