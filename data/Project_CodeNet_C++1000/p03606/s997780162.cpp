
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    int count=0;
    rep(i,n){
        int l,r;
        cin >> l >> r;
        count =count+r-l+1;
    }
    cout << count << endl;
}