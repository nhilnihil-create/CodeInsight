#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(auto& t : a) cin >> t;
    vector<int> pos(N);
    for(int i=0;i<N;i++) pos[a[i]-1] = i;
    long long res = 0;
    set<int> S;
    S.insert(-1);
    S.insert(N);
    for(int i=0;i<N;i++){
        int p = pos[i];
        auto it = S.upper_bound(p);
        long long m = 1;
        m *= *it-p;
        --it;
        m *= p-*it;
        res += (i+1)*m;
        S.insert(p);
    }
    cout << res << endl;
}