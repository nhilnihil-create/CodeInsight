#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 51;
ll c[MAX][MAX];

void makeCombi(int n){
    c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i; j++){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
            //printf("c[%d][%d] = %ld\n", i, j, c[i][j]);
        }
    }
}

int main(){
    int n, p;
    int even = 0, odd = 0;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a & 1) odd++;
        else even++;
        //cout << odd << " " << even << endl;
    }
    makeCombi(n);
    ll ans = 0;
    if(p == 0){
        for(int i = 0; i <= odd; i += 2){
            for(int j = 0; j <= even; j++){
                ans += max(1LL, c[even][j]) * max(1LL, c[odd][i]);
                //cout << c[even][j] << " " << c[odd][i] << endl;
            }
        }
    } else {
        for(int i = 1; i <= odd; i += 2){
            for(int j = 0; j <= even; j++){
                ans += max(1LL, c[even][j]) * max(1LL, c[odd][i]);
                //cout << c[even][j] << " " << c[odd][i] << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}