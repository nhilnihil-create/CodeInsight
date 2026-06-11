// ABC049C.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;
#define modP 1000000007

ll myPower2(int num){
	if( num == 0) return 1;
	return (myPower2(num-1)*2)%modP;
}


int main()
{
	int n;
	cin>>n;
	int *A = new int[n];
	int *B = new int[2*n];
	rep(i,2*n) B[i] = 0;
	rep(i,n){
		cin>>A[i];
		B[A[i]]++;
	}
	bool ans = true;
	if( n % 2 == 1){
		if( B[0] != 1){
			ans = false;
		}else{
			for(int i = 2; i <= (n-1); i = i * 2){
				if( B[i] != 2){
					ans = false;
					break;
				}
			}
		}
	}else{
		for(int i = 1; i <= (n-1); i = i + 2){
			if(B[i] != 2){
				ans = false;
				break;
			}
		}
	}
	if( ans == false){
		cout<<0<<endl;
	}else{
		int num;
		if( n % 2 == 0){
			num = n / 2;
		}else{
			num = (n-1)/2;
		}
		cout<<myPower2(num)<<endl;
	}

	return 0;
}

