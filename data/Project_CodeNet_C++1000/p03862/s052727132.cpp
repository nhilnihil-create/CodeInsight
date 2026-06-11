#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;
typedef long long ll;

int main()
{
	ll N, x;
	ll a[100000];
	
	cin >> N >> x;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	ll sumTwo[100000];
	for(int i = 0; i < N-1; i++){
		sumTwo[i] = a[i] + a[i+1];
	}
	
	// まず、隣接する3つの箱の２ペアの総和が多い場合を処理する
	ll count = 0;
	for(int i = 0; i < N-2; i++){
		if(sumTwo[i] > x && sumTwo[i+1] > x){
			ll eat = min(sumTwo[i] - x, sumTwo[i+1] - x);
			eat = min(eat, a[i+1]); // 減らす対象の箱のキャンディの数が0未満になってはいけない
			count += eat;
			a[i+1] -= eat;
			sumTwo[i] -= eat;
			sumTwo[i+1] -= eat;
		}
	}
	// 残ったペアを処理する場合は、どちらの箱を処理しても同じ
	for(int i = 0; i < N-1; i++){
		if(sumTwo[i] > x){
			count += sumTwo[i] - x;
		}
	}
	
	cout << count << endl;
	
	return 0;
}