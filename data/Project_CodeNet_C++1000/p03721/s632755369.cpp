#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
    long n,k,ai,bi;
    cin >> n >> k;
    vector<long> l(100001);
    rep(i,n){
        cin >> ai >> bi;
        l[ai]+=bi;
    }
    for (int i = 0; i < 100001; i++){
        if (l[i] > 0){
            k-=l[i];
            if (k <= 0){
                cout << i << endl;
                return 0;
            }
        }
    }
}