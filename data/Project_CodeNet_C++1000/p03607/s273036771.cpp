#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    map<ll, int> p;

    for (int i = 0; i < A.size(); i++)
    {
        if(p[A[i]] == 1) {
            p[A[i]] = 0;
        } else
        {
            p[A[i]] += 1;
        }
        
        
        
    }
    
    ll ans = 0;
    
    for (auto i : p)
    {
        if(i.second >= 1)
        ans += 1;
    }
    
    cout << ans << endl;
    
    return 0;

}