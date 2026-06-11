#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    ll cnt[1000000];
    rep(i,1000000) cnt[i] = 0;
    rep(i,n){
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    ll sub=0;
    rep(i,1000000){
        if(cnt[i]==0)continue;
        sub+=cnt[i]-1;
    }
    if(sub%2==1) sub++;
    cout << n - sub << endl;
    return 0;
}