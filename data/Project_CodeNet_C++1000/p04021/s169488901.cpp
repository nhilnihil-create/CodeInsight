#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define PB push_back
#define PII pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);

const int maxn = 2e5;
ll a[maxn] , b[maxn];
set <ll> s;

int main() {
    int n , cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a , a + n);
    for (int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            s.insert(a[i]);
        }
    } 
    for (int i = 0; i < n; ++i) {
        if(i % 2 != 0 && s.find(b[i]) != s.end()) {
            cnt++;
        }
    }
    cout << cnt << endl;
}