#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const int MAXN = 2e5 + 2;
const ll INF = 1e9 + 1;
const ld pi = acos(-1);
const int dx[4] = {-1, -1, 1, 1};
const int dy[4] = {-1, 1, -1, 1};

ll n, a[MAXN], l[MAXN], r[MAXN], ans;
stack<ll> s;

int main(){
 
    faster();

    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    a[0] = a[n + 1] = -INF;

    s.push(0);
    for(int i = 1; i <= n; ++i){
        while(a[s.top()] > a[i])
            s.pop();
        l[i] = s.top() + 1;
        s.push(i);
    }
    while(!s.empty())
        s.pop();

    s.push(n + 1);
    for(int i = n; i >= 1; --i){
        while(a[s.top()] > a[i])
            s.pop();
        r[i] = s.top() - 1;
        s.push(i);
    }
    while(!s.empty())
        s.pop();

    for(int i = 1; i <= n; ++i){
        ans += (i - l[i] + 1) * (r[i] - i + 1) * a[i];
    }

    cout << ans;

    return 0;
}
