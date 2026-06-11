//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc018/tasks/agc018_a

//ユークリッドの互除法と最大公約数
//https://qiita.com/drken/items/0c88a37eec520f82b788

//ユークリッドの互除法はそもそも
//「mod mにおいてa=bの時
//　GCD(a,m)=GCD(b,m)が成立する」
//という原理から来ている

//参考：https://drken1215.hatenablog.com/entry/2020/03/22/205100

//この問題は操作そのものがユークリッドの互除法になっている
//A[0]~A[N-1]全部の最大公約数(gcd)をdとおく
//gcd(a,b)=gcd(a-b,b)であることから
//操作によって作れる数はdを必ず約数に含む

//A[0]~A[N-1]のうち最大のものをA[MAX]とすると
//A[MAX]-d,A[MAX]-2d,A[MAX]-3d.....0　が全部作れる
//これはすなわち0~A[MAX]のうち、dを約数に持つものは全て作れることを表す

//よってKがこれのどれかと一致していれば良い

//ちなみにA[MAX]-d,A[MAX]-2d,A[MAX]-3d.....0　が全部作れると書いたが、
//この時、A[MAX]ではなく例えば最大値でもなんでもない適当な要素A[i]を使うと
//A[i]-d,A[i]-2d,A[i]-3d.....0
//が作れる
//しかしdはAの要素全部の最大公約数であるためA[i]はdを約数にもつ
//これによってA[i]-d,A[i]-2d,A[i]-3d.....0は
//A[MAX]-d,A[MAX]-2d,A[MAX]-3d.....0にも含まれていることとなる
//よってA[MAX]の時だけ調べれば良くなる

//適当に要素A[i],A[j]を抽出すると
//どっちもdを約数にもつのでA[i]-A[j]も必ずdを約数にもつ
//さらにそこから適当な要素を引いてもやはりdを約数にもつ
//つまり絶対に、できる数値はdの約数を持たなければならない

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

//計算量はどちらもO(logN)
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b) { return a/gcd(a,b)*b;}

LL N,K;
vector<LL> A;

string ans = "IMPOSSIBLE";

void solve(){
	sort(A.begin(),A.end());//昇順
	LL gcd_A = A[N-1];
	for(int i=0;i<=N-2;i++) gcd_A = gcd(gcd_A,A[i]);

	if(K%gcd_A==0 && K<=A[N-1]) ans = "POSSIBLE";
}

int main(){
    cin >> N >> K;
    A = vector<LL>(N);
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

    cout << ans << endl;
    return 0;
}