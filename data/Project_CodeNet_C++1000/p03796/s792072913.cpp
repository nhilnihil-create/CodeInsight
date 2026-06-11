#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1000000007;

int main()
{

    int N;;
    cin >> N;
    ll power = 1;
    rep(i, N){
        power = (i+1)*power%INF;
    }
    cout << power << endl;

    return 0;
}