/*
      author  : nishi5451
      created : 14.08.2020 14:11:26
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(),l.end(),greater<int>());
    int sum = 0;
    rep(i,k) sum += l[i];
    cout << sum << endl;
    return 0;
}