#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    vector <int> a(n);
    rep(i, n) cin >> a.at(i);
    vector <int> cnt(n + 1, -1);
    cnt.at(1) = 0;
    int now = 1;
    while(cnt.at(2) == -1){
        int next = a.at(now - 1);
        if(cnt.at(next) != -1){
            cout << -1 << endl;
            return 0;
        }
        cnt.at(next) = cnt.at(now) + 1;
        now = next;
    }
    cout << cnt.at(2) << endl;
}