#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define INF 1e9
#define pb push_back
using namespace std;
typedef long long ll;
using pii = pair<ll, ll>;

int main() {
    string s;
    cin >> s;
    int n;
    n = s.size();
    cout << s[0] + to_string(n-2) +s[n-1];
}