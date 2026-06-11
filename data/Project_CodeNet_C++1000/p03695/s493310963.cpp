#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    int n; cin >> n;
    set<int> c;
    int p = 0;
    int l = 0;
    rep(i,n){
        int tmp; cin >> tmp;
        for(int j = 1; j <= 8; j ++){
            if(tmp < 400*j) {
                c.insert(j);
                break;
            }
            if(j == 8){
                p ++;
            }
        }
    }

    l = c.size();

    if(p == 0) {
        cout << l << " " << l;
    }
    else if(l == 8) cout << 8 << " " << 8 + p;
    else if(l == 0) {
        cout << 1 << " " << p;
    }else{
        cout << l << " " << l+p;
    }

    return 0;
}









