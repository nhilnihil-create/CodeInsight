#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    // 予選通過者の数pass, 海外学生の数fnum，海外学生の予選通過ラインfpts
    ll n, a, b;
    cin >> n >> a >> b;
    ll pass = 0, fnum = 0;
    string s;
    cin >> s;
    rep(i, 0, n){
        auto cur = s[i];
        if(cur == 'a'){
            if(pass < a + b){
                cout << "Yes" << endl;
                pass++;
            }else{
                cout << "No" << endl;
            }
        }
        if(cur == 'b'){
            if(pass < a + b && fnum < b){
                cout << "Yes" << endl;
                fnum++;
                pass++;
            } else {
                cout << "No" << endl;
            }
        }
        if(cur == 'c') {
            cout << "No" << endl;
        }
    }
    return 0;
}