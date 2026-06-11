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

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

int main(){
   int n,k;
   cin >> n >> k;
   vector<int> a;
   REP(i,n){
       int x;
       cin >> x;
       if(x < k) a.push_back(x);
   }

   int m = a.size();
   sort(all(a));

   // bitsetで作ることのできる部分和の位置のフラグをたてていく
   // b[i][0][j] := i番目までのカードを使って、jを作ることができるかどうか
   // b[i][1][j] := N ~ i番目までのカードを使って、jを作ることができるかどうか
   // (作れる数字セット) = (前までの和で作れるセット) | (前までの和で作れるセット + 対象の数字を選ぶことによる並行移動)
   bitset<5001> b[m][2];
   b[0][0] = 1;
   b[m - 1][1] = 1;
   REP(i, m - 1) b[i + 1][0] = b[i][0] | (b[i][0] << a[i]);
   REP(i, m - 1) b[m - i - 2][1] = b[m - i - 1][1] | (b[m - i -1][1] << a[m - i -1]);

   int ok = m, ng = -1;
   while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        bool flag = false;

        for(int i = k - a[mid]; i < k; i++){
            for(int j = 0; j < i + 1; j++){
                if(b[mid][0][j] && b[mid][1][i - j]){
                    // mid 意外で k - a_mid 以上 k 以下の値を作ることができる場合
                    flag = true;
                    break;
                }
            }
        }

       if(flag) ok = mid;
       else ng = mid;
   }
   cout << ok << endl;

   return 0;
}