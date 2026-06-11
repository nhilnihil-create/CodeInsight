#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> to(n);
    REP(i, m){
        ll ai, bi;
        cin >> ai >> bi;
        ai--; bi--;
        to.at(ai).push_back(bi);
        to.at(bi).push_back(ai);
    }

    vector<bool> vis(n, false);
    deque<ll> path;
    path.push_front(0);
    path.push_back(to.at(0).back());
    to.at(0).pop_back();
    vis.at(0) = true;
    vis.at(path.back()) = true;
    while(to.at(path.front()).size()){
        if(vis.at(to.at(path.front()).back())){
            to.at(path.front()).pop_back();
        }else{
            vis.at(to.at(path.front()).back()) = true;
            path.push_front(to.at(path.front()).back());
        }
    }
    while(to.at(path.back()).size()){
        if(vis.at(to.at(path.back()).back())){
            to.at(path.back()).pop_back();
        }else{
            vis.at(to.at(path.back()).back()) = true;
            path.push_back(to.at(path.back()).back());
        }
    }

    cout << path.size() << endl;
    while(!path.empty()){
        cout << path.front() + 1;
        path.pop_front();
        if(path.empty()){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
    return 0;
}
