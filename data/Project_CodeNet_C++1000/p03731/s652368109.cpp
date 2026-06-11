#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,t;
    cin >> n >> t;

    vector<int> ti(n);
    rep(i,n) cin >> ti[i];

    int sum = t;

    rep(i,n-1){
        if(ti[i+1] - ti[i]  < t){
            sum += ti[i + 1] - ti[i];
        }
        else{
            sum += t ;
        }
        
    }
    cout << sum << endl;
    return 0;
}