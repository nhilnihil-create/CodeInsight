#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

/*
 * 問題文
 *
 * 長さ n の数列 a1,...,an が与えられます。 空の数列 b に対して、以下の操作を n回行うことを考えます。
 *  i回目には数列の i番目の要素 ai を bの末尾に追加する。
 *  bを逆向きに並び替える。
 *
 * この操作をしてできる数列 bを求めて下さい。
 *
 */

long long N;
vector<long long> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N ;
	for(int i=0; i<N; i++){
		long long u;
		cin >> u;
		A.push_back(u);
	}

	if(N == 1){
		printf("%lld\n", A[0]);
		return 0;
	}
	else if(N == 2){
		printf("%lld %lld\n", A[1], A[0]);
		return 0;
	}
	else if(N == 3){
		printf("%lld %lld %lld\n", A[2], A[0], A[1]);
		return 0;
	}
	else if(N == 4){
		printf("%lld %lld %lld %lld\n", A[3], A[1], A[0], A[2]);
		return 0;
	}

	int print_zero = 0;
	for(int i=A.size() - 1; i >= 0; i -= 2){
		if(i == A.size() - 1){
			printf("%lld", A[i]);
		}
		else{
			printf(" %lld", A[i]);
			if(i == 0){
				print_zero = 1;
			}
		}
	}
	for(int i=0; i<A.size(); i += 2){
		if(i == 0 && print_zero == 1){
			i++;
		}
		printf(" %lld", A[i]);
	}
	printf("\n");
	return 0;
}