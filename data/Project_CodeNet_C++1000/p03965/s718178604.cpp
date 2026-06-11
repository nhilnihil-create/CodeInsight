#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    string s;
    cin >> s;
    int ans = 0;
    int cnt = 0;
    int g = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'g'){
            cnt += 1;
            g += 1;
        }else{
            if (cnt > 0) cnt -= 1;
            else ans -= 1;
        }
    }
    if (cnt / 2 < g) ans += cnt / 2;
    else ans += g;
    cout << ans << endl;
    return 0;
}