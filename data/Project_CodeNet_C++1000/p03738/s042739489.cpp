#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define pf push_front
#define eb emplace_back
using namespace std;
typedef long long ll;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b; return true;} return false;}
template<class t,class u> bool chmin(t&a,u b){if(a>b){a=b; return true;} return false;}
template<class t,class u> t MAX(t a,u b){if(a>=b) return a; return b;}
template<class t,class u> t MIN(t a,u b){if(a<=b) return a; return b;}
template<class t> int SIZE(t s){return (int)s.size();}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vvi=vc<vc<int>>;
using pi=pair<int,int>;
using vi=vc<int>;
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
const long long INF = 1LL << 60;

int main(){
    cout << fixed << setprecision(20);
    string s,t; cin >> s >> t;
    int ss = SIZE(s); int st = SIZE(t);
    if(ss > st) cout << "GREATER" << endl;
    else if(ss == st){
        rep(i,ss){
            if(s[i]-'0' > t[i]-'0'){
                cout << "GREATER" << endl;
                return 0;
            }
            else if(s[i]-'0' < t[i]-'0'){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    else cout << "LESS" << endl;
    return 0;
}
