//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc014/tasks/agc014_b

//参考：
//http://ronly.hatenablog.com/entry/2017/10/14/201150

//ポイント1：
//木の根をrとするとクエリ(a,b)は(r,a)と(r,b)に分割できる
//ポイント2：
//クエリ(r,i)をa_i回行うとする
//すべてのiに対し、a_iが偶数であれば良い
//奇数回しかクエリに出ていない数の中で一番深いノードをxとすると
//xの上の辺には+1しかされていないため全てを偶数にすることはできない

//考え方：
//一本の鎖を考える

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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;
LL A[100000],B[100000];

string ans = "YES";

void solve(){
	vector<LL> counter(N+1,0);//点iの出現回数をcounter[i]とおく
	for(int i=0;i<M;i++){
		counter[A[i]]++;
		counter[B[i]]++;
	}
	for(int i=0;i<=N;i++){
		if(counter[i]%2==1){
			ans = "NO";
			return;
		}
	}
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) cin >> A[i] >> B[i];

    solve();

	cout << ans << endl;
    return 0;
}