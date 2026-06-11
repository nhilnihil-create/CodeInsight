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
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'g'){
            cnt += 1;
        }else{
            if (cnt > 0) cnt -= 1;
            else ans -= 1;
        }
    }
    ans += cnt / 2;
    cout << ans << endl;
    return 0;
}