#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> make(ll N, int y){
    if(N == 0)
        return {};
    if(N == 1){
        return {y, y};
    }
    if(N == 2){
        return {y + 1, y, y, y + 1};
    }
    vector<int> ff;
    if(N % 2 == 0){
        ff = make(N-1, y + 1);
        int m = ff.size();
        ff.insert(ff.begin() + m/2, y);
        ff.insert(ff.begin() + m/2, y);
    }
    else{
        ff = make(N/2, y + 1);
        int m = ff.size();
        ff.insert(ff.begin() + m/2, y);
        ff.insert(ff.begin(), y);
    }
    return ff;
}

int main(){
    fastIO;
    ll m;
    cin >> m;
    vector<int> res = make(m, 1);
    cout << res.size() << "\n";
    for(auto p : res)
        cout << p << " ";
    return 0;
}