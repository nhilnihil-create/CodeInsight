#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){
    int n, i, flag, flag2, count = 0, mem = -1;
    cin >> n;
    int a[n];
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    flag = n%2;
    flag2 = 1^flag;
    for(i=0; i<n; i++){
        if(((i+flag)/2)*2 + flag2 != a[i]){
            cout << 0;
            return 0;
        }
    }
    ll res = 1;
    for(int i=0; i<n/2; i++){
        res *= 2;
        res %= MOD;
    }
    cout << res;
    return 0;
}