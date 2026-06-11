#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 20005;

int n;
int a[maxn], b[maxn];
int p[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        a[i] = i * n * 2;
        b[i] = (n + 1 - i) * n * 2;
    }
    for(int i = 1;i <= n;i++){
        cin >> p[i];
        a[p[i]] += i - 1;
        b[p[i]] += i - 1;
    } 
    for(int i = 1;i <= n;i++){
        cout << a[i] << (i == n ? '\n' : ' ');
    }
    for(int i = 1;i <= n;i++){
        cout << b[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
