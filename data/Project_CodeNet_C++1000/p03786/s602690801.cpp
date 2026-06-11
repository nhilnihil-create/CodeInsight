/**
*    author:  souzai32
*    created: 14.08.2020 14:53:26
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());

    int count=1;
    rep(i,n-1){
        if(a.at(i)*2>=a.at(i+1)) count++;
        else count=1;
        a.at(i+1)+=a.at(i);
    }
    cout << count << endl;

    return 0;
}