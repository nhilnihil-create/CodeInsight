#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
 
 
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

// ここから編集

auto build_SA(string s){

    vector<pair<string, int>> v;

    int len = s.size();
    string t = "$";
    v.emplace_back(t, len--);
    for(int i=s.size()-1; i>=0; i--){
        t = s[i] + t;
        v.emplace_back(t, len--);
    }

    sort(all(v));

    vector<int> SA;
    for(int i=0; i<v.size(); i++) SA.push_back(v[i].second);

    for(auto e: SA) cout << e << endl;
    return SA;
}
void BWT(string s){

    auto SA = build_SA(s);

    vector<char> v;
    for(int i=0; i<SA.size(); i++){
        if(SA[i] == 0){
            v.push_back('$');
        }else{
            v.push_back(s[SA[i]-1]);
        }
    }
    
    for(int i=0; i<v.size(); i++){
        cout << SA[i] << " " << v[i] << endl;
    }
}

int N;

int cnt[200010][4];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    
    int n; cin >> n;

    map<int, int> mp;
    vector<int> a(n);
    int mi=INT_MAX, mx=0;
    REP(i,n)cin >> a[i],mx=max(mx,a[i]),mi=min(mi,a[i]),mp[a[i]]++;
    if(mx-mi >= 2){
        cout << "No"<< endl;
    }else{
        if(mi == mx){
            if(2*mi <= n){
                cout << "Yes" << endl;
            }else if(mi == n-1){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            int A = mx;
            int x = mp[A-1];
            int y = mp[A];
            if(x < A && 2*(A-x) <= y){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    

    //最小が 1: 全体の種類数高々2種類
    //       2: 
    // len() = n && 全ての要素がn-1 -> true


    return 0;
}
