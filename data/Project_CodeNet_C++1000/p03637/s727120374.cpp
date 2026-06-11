#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    int multiple_4_count = 0;
    int multiple_2_count = 0;
    int other_count = 0;
    rep(i,N){
        if (A[i] % 4 == 0){
            multiple_4_count++;
        }
        else if (A[i] % 2 == 0){
            multiple_2_count++;
        }
        else{
            other_count++;
        }
    }

    if (multiple_4_count + 1 >= (multiple_2_count+other_count)){
        cout << "Yes" << endl;
    }
    else if (multiple_4_count >= other_count){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}