#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<Pll> v;
    map<ll,ll> mp;
    rep(i,N){
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A.begin(), A.end(), greater<ll>());
    for(auto& e:mp){
        v.push_back(e);
    }
    ll tmp = 0;
    bool flag = false;
    for(int i = v.size() -1 ;i>=0;i--){
        if(v[i].second >= 4){
            if(!flag){
                cout << v[i].first*v[i].first << endl;
                return 0;
            }else{
                cout << tmp*v[i].first << endl;
                return 0;
            }
        }else if(v[i].second >= 2){
            if(flag){
                cout << tmp*v[i].first << endl;
                return 0;
            }
            flag = true;
            tmp = v[i].first;
        }
    }
    cout << 0 << endl;
}
