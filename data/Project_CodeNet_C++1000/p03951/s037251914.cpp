#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int N, string const &s, string const &t, int &ans){

    int cnt{};
    auto iter_t = t.begin();
    auto iter_s = s.begin();

    while(iter_s != s.end()){
        
        if((*iter_s) == (*iter_t)){
            ++cnt;
            ++iter_t;
        }
        else{
            cnt = 0;
            iter_t = t.begin();

            if((*iter_s) == (*iter_t)){
                ++cnt;
                ++iter_t;
            }
        }
        ++iter_s;
    }

    ans = 2*N - cnt;

    return;
}

int main(){

    int N;
    string s, t;
    cin >> N >> s >> t;

    int ans{};
    solver(N, s, t, ans);

    cout << ans << endl;

    return 0;
}

