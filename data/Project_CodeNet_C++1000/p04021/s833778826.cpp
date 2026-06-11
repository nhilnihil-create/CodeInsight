//g++ -std=c++14 test.cpp -o test.out

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

LL N;
LL A[100001];

LL ans = 0;

void solve(){
	//Aの大小関係をもとに順列みたいにする
	//例えばA = {10,8,3,5,2}みたいな数列なら{5,4,2,3,1}みたいに変換
	map<LL,int> ind;//数xがAの何番めにあるかをind[x]とする
	for(int i=1;i<=N;i++) ind[A[i]] = i;
	int counter = 1;
	for(auto iter=ind.begin();iter!=ind.end();iter++){
		A[iter->second] = counter;
		counter++;
	}
	//インデックスが偶数番目同士、奇数番目同士は好きなだけ入れ替えられるので
	//偶数番目⇄奇数番目の入れ替えの最小回数を求めればそれが答え
	for(int i=1;i<=N;i++){
		if(i%2!=A[i]%2) ans++;
	}
	ans /= 2;
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];

    solve();

	cout << ans << endl;
    return 0;
}