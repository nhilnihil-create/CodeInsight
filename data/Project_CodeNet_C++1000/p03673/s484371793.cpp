/**
*    author:  souzai32
*    created: 02.08.2020 18:27:17
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> b;
    int a;

    rep(i,n){
        cin >> a;
        if(i%2){
            b.push_back(a);
        }
        else{
            auto it=b.begin();
            it=b.insert(it,a);
        }
    }
    if(n%2==0) reverse(b.begin(),b.end());

    rep(i,n-1) cout << b.at(i) << ' ';
    cout << b.at(n-1) << endl;

    return 0;
}