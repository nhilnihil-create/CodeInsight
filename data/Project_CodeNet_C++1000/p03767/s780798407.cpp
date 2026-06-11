#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 1e5 + 5;

int a[maxn * 3];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n * 3;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n * 3);
    ll sum = 0;
    for(int i = n + 1;i <= n * 3;i += 2){
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
