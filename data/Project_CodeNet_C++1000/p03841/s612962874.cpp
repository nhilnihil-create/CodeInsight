#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=0;
vector<ll> A;
vector<pair<ll,ll>> P;
vector<vector<ll>> G;
string S;
map<ll,ll> MP, MPS;

signed main(){
    cin >> N;
    A.resize(N*N, -1);
    for(int i=1;i<=N;i++) {
        ll a;
        cin >> a;
        P.push_back(make_pair(a, i));
        A[a-1] = i;
        MPS[i] = a;
        MP[i]++;
    }
    sort(P.begin(), P.end());
    ll itr=0;
    for(int i=0;i<N*N;i++) {
        //cout << "OK" << endl;
        if(A[i]!=-1) {
            if(MP[A[i]]!=A[i]) {
                //cout << MP[A[i]]+1 << " " << A[i] << endl;
                cout << "No" << endl;
                return 0;
            }
            continue;
        }
        if(itr<N) {
            while(MP[P[itr].second]==P[itr].second) {
                itr++;
            }
            if(itr<N) {
                A[i] = P[itr].second;
                MP[P[itr].second]++;
            }
            else {
                while(1) {
                    if(MP[P[tmp].second]<N) {
                        A[i] = P[tmp].second;
                        MP[P[tmp].second]++;
                        break;
                    }
                    else tmp++;
                }
            }
        }
        else {
            while(1) {
                if(MP[P[tmp].second]<N) {
                    A[i] = P[tmp].second;
                    MP[P[tmp].second]++;
                    break;
                }
                else tmp++;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i=0;i<N*N;i++) {
        cout << A[i] << endl;
    }
    return 0;
}