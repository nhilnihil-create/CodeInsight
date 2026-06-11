#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

ll A[300100];
ll AY[200100];
int main(){
    int N;
    cin >> N;
    priority_queue<ll, vector<ll>, greater<ll> > pr;
    ll X = 0;
    ll Y = 0;
    REP(i,3*N){
        ll a;
        cin >> a;
        A[i] = a;
        if(i < N) {
            pr.push(a);
            X += a;
        }
        else{
            AY[i-N] = a;
        }
    }
    sort(AY, AY+2*N);
    map<ll, int> in;
    map<ll, int> out;
    for(int i = 0; i < N; i++){
        Y += AY[i];
        in[AY[i]]++;
    }
    for(int i = N; i < 2*N; i++){
        out[AY[i]]++;
    }


    ll ans = X-Y;
    for(int p = N; p < 2*N; p++){
        ll a = A[p];

        ll x = pr.top();
        if(a > x){
            pr.pop();
            pr.push(a);
            X += a - x;
        }

        auto bound = in.end();
        bound--;
        if(bound->first >= a){
            auto m = out.begin();
            ll y = m->first;
            Y += y - a;
            m->second--;
            if(m->second == 0) out.erase(m->first);

            in[a]--;
            if(in[a] == 0) in.erase(a);
            in[y]++;
        }
        else{
            out[a]--;
            if(out[a] == 0) out.erase(a);
        }

        //cout<< X << " " << Y << endl;
        ans = max(ans, X-Y);
    }

    cout << ans << endl;
    return 0;
}
