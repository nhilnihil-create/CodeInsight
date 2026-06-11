#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> v;
    priority_queue<ll> lque;
    priority_queue<ll, vector<ll>, greater<ll> > gque;

    ll smf = 0, smb = 0;
    for(int i = 0; i < 3*N; i++) {
        ll x;
        cin >> x;
        if(i < N) {gque.push(x); smf += x; }
        else if(i < 2*N) {v.push_back(x); }
        else {lque.push(x); smb += x; }
    }

    vector<ll> smfv, smbv;
    smfv.push_back(smf);
    smbv.push_back(smb);
    for(int i = 0; i < N; i++){
        gque.push(v[i]);
        ll n = gque.top(); gque.pop();

        smf = smf - n + v[i];
        smfv.push_back(smf);
        
        lque.push(v[N-1-i]);
        n = lque.top(); lque.pop();
        smb = smb - n + v[N-1-i];
        smbv.push_back(smb); 
    }

    ll ans = -1e18-1;
    for(int i = 0; i < N+1; i++) {
        ans = max(ans, smfv[i] - smbv[N-i]);
    }

    cout << ans << endl;

    return 0;
}