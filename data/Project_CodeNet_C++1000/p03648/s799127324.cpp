#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define MAX_N 100000 + 100
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 53;
ll seq[maxn];
int main(){
    ll k;
    cin >> k;
    if (k == 0){
        cout << 2 << endl;
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    if (k == 1){
        cout << 2 << endl;
        cout << 0 << ' '  << 2 << endl;
        return 0;
    }
    if (k <= 50){
        cout << k << endl;
        for (int i = 1;i <= k;i++) cout << i << ' ';
        cout << endl;
        return 0;
    }
    ll ks = k / 50;
    ks--;
    ll a = 1;

    for (int i = 1;i <= 50;i++){
        seq[i] = (i + ks);
    }
    k %= 50;
    for (int i = 0;i < k;i++){
        int index = 50 - i;
        seq[index]++;
    }
    cout << 50 << endl;
    for (int i = 1;i <= 50;i++) cout << seq[i] << ' ';
    cout << endl;
    return 0;
}
