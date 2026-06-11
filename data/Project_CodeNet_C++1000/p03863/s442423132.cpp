#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

/*
重複する文字をまず考えない
間が奇数個なら先手の勝利だが端が重複するなら後手の勝利
間が偶数個なら後手の勝利だが端が重複するなら先手の勝利

重複する文字は...
重複する前に狙って取り除けば取り除いたときに重複せずに済む
よって最後3文字残ったとき以外は必ず回避可能
*/

int main() {
    string S;
    cin >> S;
    int N = S.length();
    if ((N % 2) ^ (S[0] == S[N-1])) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }


}
