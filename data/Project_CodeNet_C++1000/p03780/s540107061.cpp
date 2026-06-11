#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);
    REP(i, N) cin >> a[i];

    sort(a.begin(), a.end(), greater<long long>());

    int ans = 0;
    set<long long> s;
    REP(i, N){
        if(a[i] >= K) continue;
        if(!s.empty()){
            set<long long> tmp(s);
            if(a[i]+*(--s.end()) >= K) ans = 0;
            else ++ans;
            for(int v: tmp){
                if(v+a[i] < K){
                    s.insert(v+a[i]);
                    s.erase(v);
                }
                else break;
            }
        }else ++ans;
        s.insert(a[i]);
        //for(int v: s) cout << v << " "; cout << endl;
    }
    cout << ans << endl;

    return 0;
}