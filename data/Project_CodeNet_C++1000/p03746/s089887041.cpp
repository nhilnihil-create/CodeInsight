#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

vector<int> g[100000];
deque<int> ans;
map<int, bool> mp;

int check_front() {
    int ret = -1;
    for(auto&& s : g[ans.front()]) {
        if(mp[s]) continue;

        ret = s;
        break;
    }
    return ret;
}

int check_back() {
    int ret = -1;
    for(auto&& s : g[ans.back()]) {
        if(mp[s]) continue;

        ret = s;
        break;
    }
    return ret;
}


int main(){
    int N, M;
    cin >> N >> M;

    REP(i, M) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    ans.push_front(0);
    ans.push_back(g[0][0]);
    mp[0] = true;
    mp[g[0][0]] = true;

    while(true) {
        int c1 = check_front();
        if(c1 != -1){
            ans.push_front(c1);
            mp[c1] = true;
            continue;
        }

        int c2 = check_back();
        if(c2 != -1){
            ans.push_back(c2);
            mp[c2] = true;
            continue;
        }

        break;
    }

    int n = ans.size();
    cout << n << endl;
    for(int i = 0; i < n; i++){
        cout << (i == 0 ? "" : " ") << ans.front() + 1;
        ans.pop_front();
    }
    cout << endl;
    
    return 0;
}