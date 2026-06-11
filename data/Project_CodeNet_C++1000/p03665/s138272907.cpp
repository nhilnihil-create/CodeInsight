#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll N, P;
    cin >> N >> P;
    vector<int> A(N);
    vector<ll> Ps(2,0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        Ps[A[i] % 2]++;
    }

    if(Ps[1] == 0){
        if(P == 0) cout << ((ll)1 << N) << endl;
        else cout << 0 << endl;
    } else{
        cout << ((ll)1 << N-1) << endl;
    }
  	return 0;
}