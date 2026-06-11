#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];

typedef long long LL;
LL suf[maxn], suf1[maxn];
int n;
int op[maxn];
int nxt[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        if(i != 1){
            cin >> s;
            if(s[0] == '-'){
                op[i] = 0;
            }else{
                op[i] = 1;
            }
        }
        cin >> a[i];
    }
    op[1] = 1;
    suf[n + 1] = 0;
    suf1[n + 1] = 0;
    for(int i = n;i >= 1;i--){
        suf[i] = suf[i + 1] + a[i];
        if(op[i] == 0)
            suf1[i] = suf1[i + 1] - a[i];
        else
            suf1[i] = suf1[i + 1] + a[i];
        //cout << suf[i] << " " << suf1[i] << endl;
    }
    int j = n + 1;
    for(int i = n;i >= 1;i--){ nxt[i] = j;
        if(op[i] == 0){
            j = i;
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        if(op[i] == 1)
            ans += a[i];
        else
            ans -= a[i];
    }
    for(int i = 1;i <= n;i++){
        if(op[i] == 1)
            continue;
        long long tmp = suf1[1] - suf1[i + 1];
        long long tmp1 = suf1[i + 1] - suf1[nxt[i]];
        long long tmp2 = suf[nxt[i]];
        ans = max(ans, tmp - tmp1 + tmp2);
    }
    cout << ans << endl;
    return 0;
}
