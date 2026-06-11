
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n, k;
    cin >> n >> k;
    int count, x;
    rep(i,n){
        cin >> x;
        if(abs(k-x) < x){
            count += 2*abs(k-x);
        }
        else count += 2*x;
    }
    cout << count << endl;
}