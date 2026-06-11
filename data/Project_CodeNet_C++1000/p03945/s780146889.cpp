#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    string s;
    cin >> s;
    char now = s[0];
    int cnt = 0;
    rep(i,s.size()){
        if(s[i] != now){
            now = s[i];
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}