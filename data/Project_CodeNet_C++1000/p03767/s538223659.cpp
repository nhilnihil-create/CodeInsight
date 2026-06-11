#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N;
    ll sum = 0;
    cin >> N;

    vector<int> v(3*N);

    rep(i, 3*N){
        cin >> v[i];
    }

    sort(v.begin(),v.end(),greater<int>());

    rep(i,2*N){
        if(i%2 == 1)
            sum += v[i];
    }

    cout << sum << endl;

    return 0;
}