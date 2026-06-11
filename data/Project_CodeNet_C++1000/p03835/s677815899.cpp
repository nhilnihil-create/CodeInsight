
//auto 関数名 = [(&:ラムダ外の引数をとる時))](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 関数の処理 }; //inside main() define function. take care of };
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }
// sort(配列変数.begin(), 配列変数.end());
// do {
//   // 順列に対する処理
// } while (next_permutation(配列変数.begin(), 配列変数.end()));
//const double PI = acos(-1); M_PI
// cout << fixed << setprecision(10);
// set<int>st{ 3,1,4,1,5,9,2,6,5,3,5 };
//     for (auto itr = st.begin(); itr != st.end(); ++itr) {
//         cout << *itr;
//     }
#include <bits/stdc++.h>
#include <regex>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
    int k,s;
    cin>>k>>s;
    int cnt=0;
    for(int i=0;i<=k;i++){
        for(int j = 0;j<=k;j++){
            if((s-i-j)<=k&&(s-i-j)>=0){
                //cout<<i<<j<<(s-i-j)<<endl;
                cnt+=1;
            }
        }
    }
    cout<<cnt<<endl;
}