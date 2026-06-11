#include <iostream>
#include <vector>

using namespace std;

bool solve(const vector<int>& a){
    vector<int> cnt(a.size(), 0);
    for(auto& t : a) cnt[t]++;
    int idx = 0;
    while(cnt[idx] == 0) ++idx;
    if(cnt[idx] >= 3) return false;
    int m = 2*idx - cnt[idx] + 1;
    if(m >= a.size()) return false;
    for(int i=idx+1;i<=m;i++){
        if(cnt[i] < 2) return false;
    }
    for(int i=m+1;i<cnt.size();i++) if(cnt[i] > 0) return false;
    return true;
}

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(auto& t : a) cin >> t;
    cout << (solve(a) ? "Possible" : "Impossible") << endl;
}