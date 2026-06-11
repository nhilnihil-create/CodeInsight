#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    int n; cin >> n;
    int sum = 0;
    vector<int> v;
    rep(i,n){
        int tmp; cin >> tmp;
        sum += tmp;
        if(tmp%10 != 0) v.push_back(tmp);
    }

    sort(v.begin(),v.end());

    if(sum%10 != 0) cout << sum;
    else if(v.empty()) cout << 0;
    else cout << sum-v[0];

    return 0;
}









