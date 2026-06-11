#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<typename T>
struct CumulativeSum{
private:
    vector<T> s;
public:
    void init(vector<T>& v){
        s.push_back(0);
        for(int i=0; i<v.size(); i++){
            s.push_back(s.back() + v[i]);
        }
    }
    T sum(int l, int r){
        l = (l < 0 ? 0 : l);
        r = (r >= s.size() ? s.size()-1 : r);
        return s[r] - s[l];
    }
};

string S, T;
vector<int> tmp;
CumulativeSum<int> SA, SB, TA, TB;
int Q;

signed main(){
    cin >> S >> T;

    tmp.assign(S.size(), 0);
    rep(i, S.size()){
        if(S[i] == 'A') tmp[i] = 1;
    }
    SA.init(tmp);
    tmp.assign(S.size(), 0);
    rep(i, S.size()){
        if(S[i] == 'B') tmp[i] = 1;
    }
    SB.init(tmp);
    tmp.assign(T.size(), 0);
    rep(i, T.size()){
        if(T[i] == 'A') tmp[i] = 1;
    }
    TA.init(tmp);
    tmp.assign(T.size(), 0);
    rep(i, T.size()){
        if(T[i] == 'B') tmp[i] = 1;
    }
    TB.init(tmp);

    cin >> Q;
    rep(i, Q){
        int ls, rs, lt, rt;
        cin >> ls >> rs >> lt >> rt;
        if((SA.sum(ls-1, rs)-SB.sum(ls-1,rs)+333333)%3
            == (TA.sum(lt-1, rt)-TB.sum(lt-1, rt)+333333)%3){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}