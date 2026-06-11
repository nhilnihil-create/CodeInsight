#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{
    int N;
    cin >> N;
    ve<ve<int>> G(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    queue<int> F,S;
    set<int> done;
    int ff = 0, ss = 0;
    F.push(0);
    S.push(N-1);
    done.insert(0),done.insert(N-1);
    
    while (done.size() < N) {
        
        queue<int> F1;
        while (!F.empty()) {
            int fff = F.front();
            F.pop();
            for (auto p : G[fff]) {
                if(done.count(p)) continue;
                ff++;
                F1.push(p);
                done.insert(p);
            }
        }
        F = F1;
        
        queue<int> S1;
        while (!S.empty()) {
            int sss = S.front();
            S.pop();
            for (auto p :G[sss]) {
                if(done.count(p)) continue;
                ss++;
                S1.push(p);
                done.insert(p);
            }
        }
        S = S1;
    }

    if(ss < ff) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    
    //cout << ff csp ss << endl;
    
    return 0;
}
