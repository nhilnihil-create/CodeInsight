#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define MOD 1000000007
#define itn int
#define enld endl
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,A,B; cin >> N >> A >> B;
    string s; cin >> s;
    int qualified = 0;
    int cnt = 0;
    int S = A+B;
    rep(i,0,SZ(s)){
        if(s[i] == 'c'){
            cout << "No" << endl;
            continue;
        }else if(s[i] == 'a'){
            if(qualified < S){
                cout << "Yes" << endl;
                qualified++;
            }else{
                cout << "No" << endl;
            }
        }else if(s[i] == 'b'){
            if(qualified < S && cnt < B){
                cout << "Yes" << endl;
                qualified++;
                cnt++;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
