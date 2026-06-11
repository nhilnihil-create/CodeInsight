#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define miele(v) min_element(v.begin(), v.end())
#define maele(v) max_element(v.begin(), v.end())
#define sum(v) accumulate(v.begin(), v.end(), 0LL)
#define lb(a, key) lower_bound(a.begin(),a.end(),key)
#define ub(a, key) upper_bound(a.begin(),a.end(),key)
#define count(a, key) count(v.begin(), v.end(), 1) 
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
using P = pair <int,int>;
using WeightedGraph = vector<vector <P>>; //to cost
using UnWeightedGraph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
void YN(bool flg) {cout<<(flg?"YES":"NO")<<'\n';}
void Yn(bool flg) {cout<<(flg?"Yes":"No")<<'\n';}
void yn(bool flg) {cout<<(flg?"yes":"no")<<'\n';}
template <typename T> 
int getIndexOfLowerBound(vector <T> &v, T x){
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
template <typename T, typename U>
int getIndexOfUpperBound(vector <T> &v, T x){
    return upper_bound(v.begin(),v.end(),x)-v.begin();
}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define DUMPOUT cerr
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
template <typename T, typename U>
istream &operator>>(istream &is, pair<T,U> &p_var) {
    is >> p_var.first >> p_var.second;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &df) {
    for(int i=0;i<df.size();i++)for(int j=0;j<df[i].size();j++)
    is >> df[i][j];
    return is;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    DUMPOUT<<'{';
    os << pair_var.first;
    DUMPOUT<<',';
    os << " "<< pair_var.second;
    DUMPOUT<<'}';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    DUMPOUT<<'[';
    for (int i = 0; i < vec.size(); i++) 
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    DUMPOUT<<']';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &df) {
  for (auto& vec : df) os<<vec;
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    DUMPOUT << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) DUMPOUT << ", ";
        itr--;
    }
    DUMPOUT << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    DUMPOUT << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) DUMPOUT << ", ";
        itr--;
    }
    DUMPOUT << "}";
    return os;
}
void print() {cout << endl;}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
}
void dump_func() {DUMPOUT << '#'<<endl;}
template <typename Head, typename... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) DUMPOUT << ", ";
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
int power(int x, int n) {
  int ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }
  return ret;
}
signed main(void) { cin.tie(0); ios::sync_with_stdio(false);
    vector <char> data(26);
    int h, w; cin>>h>>w;
    vector <vector<char>> g(h,vector <char>(w));
    cin>>g;
    rep(i, h) rep(j, w){
        data[g[i][j] - 'a']++;
    }
    int one=0, two=0, four=0;
    rep(i, 26){
        if(data[i] % 2 == 1){
            one++;
            data[i]--;
        }
        if(data[i]%4 == 0){
            four += data[i];
        }else if(data[i]%2 == 0){
            two += 2;
            four += data[i] - 2;
        }
    }
    if(h%2 == 0 && w % 2 ==0){
        Yn(!one && ! two);
    }else if(h%2 == 0 || w %2 == 0){
        int x = 0;
        if(h%2 == 0) x=h; else x = w;
        Yn(!one&&x>= two);
    }else{
        Yn(one <= 1&& two <=(h+w-2));
    }
}
