#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int main()
{
    int N;
    cin >> N;
    char S1[60], S2[60];
    cin >> S1;
    cin >> S2;

    vector<bool> Q;
    for(int i = 0; i < N; ){
        if(i+1 < N && S1[i] == S1[i+1]) {
            Q.push_back(false);
            i += 2;
        }
        else {
            Q.push_back(true);
            i += 1;
        }
    }

    ll res = 0;
    for(int i = 0; i < Q.size(); ++i) {
        if(i == 0) {
            if(Q[i]) res += 3;
            else res += 6;
            continue;
        }

        bool prev = Q[i-1], cur = Q[i];
        if(prev && cur) { res *= 2; res %= mod; }
        else if(!prev && cur) { res *= 1; }
        else if(prev && !cur) { res *= 2; res %= mod;}
        else { res *= 3; res %= mod; }
    }
    cout << res << endl;
    return 0;
}