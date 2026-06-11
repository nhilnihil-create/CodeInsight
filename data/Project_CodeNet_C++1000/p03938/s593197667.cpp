#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define saken string
#define erba continue
using namespace std;

const int MAXN = 2e4 + 10;
int n, p[MAXN], a[MAXN], b[MAXN];


int main(){

mal

cin >> n;

for(int i = 1; i <= n; ++i) {
    cin >> p[i];
    a[i] = i * n;
    b[n - i + 1] = i * n;
}

int cnt = n - 1;

for(int i = 1; i <= n; ++i) {
    b[p[i]] -= cnt;
    cnt--;
}

cnt = n - 1;

for(int i = n; i >= 1; --i) {
    a[p[i]] += cnt;
    cnt--;
}

for(int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
}

cout << '\n';

for(int i = 1; i <= n; ++i) {
    cout << b[i] << ' ';
}

return 0;
}

