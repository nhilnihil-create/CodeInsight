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
template <typename T> bool chmax(T &a, T b) {if(a < b) {a = b;return 1;}return 0;}
template <typename T> bool chmin(T &a, T b) {if(a > b) {a = b;return 1;}return 0;}



const int max_n_com = 51;
ve<vl> combination(max_n_com,vl(max_n_com,-1));
ll comb(int a, int b){
    
    if(combination[a][b] > 0) return combination[a][b];
    else if(a < b) return 0;
    else if(a == 0 || b == 0 || a == b) return combination[a][b] = 1;
    else return combination[a][b] = comb(a-1,b-1) + comb(a-1,b);
    
    
}




int main()
{
    int N,A,B;
    cin >> N >> A >> B;
    vl v(N);
    in(N,v);
    sort(all(v));
    reverse(all(v));
    
    
    ll a = 0;
    map<ll,int> V;
    rep(i,A) a += v[i],V[v[i]]++;
    ld ave = (ld)(a) / (ld)(A);

    outset(10);
    cout << ave << endl;
    

    if(V.size() == 1){
        
        ll ans = 0;
        int aa = V[v[A-1]];
        reps(i,A,N){
            if(v[A-1] == v[i]) V[v[i]]++;
            else break;
        }
        reps(i,A,B+1){
            ans += comb(V[v[A-1]],i);
            //cout << V[v[A-1]] csp i << endl;
        }
        
        cout << ans << endl;
        
        
        
    }else{
        int aa = V[v[A-1]];
        reps(i,A,N){
            if(v[A-1] == v[i]) V[v[i]]++;
            else break;
        }
        
        cout << comb(V[v[A-1]], aa) << endl;
        //cout << V[v[A-1]] csp aa << endl;
    }
    
    
    
    
    

    return 0;
}
