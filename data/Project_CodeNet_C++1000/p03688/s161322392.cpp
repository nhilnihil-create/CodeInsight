//agc016_b.cpp
//Thu May 14 21:40:27 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n+1];
	fill(a,a+n+1,0);
	int first;
	for (int i=0;i<n;i++){
		int x;
		cin >> x;
		if (i==0){
			first = x;
		}
		a[x]++;
	}

	int pos1 = first;
	int pos2 = first+1;

	if (a[pos1]+a[pos1-1]==n &&
		a[pos1-1]>=max(2*pos1-n,0)){
		int max = 0;
		if (pos1==n){
			max = pos1;
		}else {
			max = pos1-1;
		}
		if (a[pos1-1]<=max){
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (a[pos2]+a[pos2-1]==n &&
		a[pos2-1]>=max(2*pos2-n,0)){
		int max = 0;
		if (pos2==n){
			max = pos2;
		}else {
			max = pos2-1;
		}
		if (a[pos2-1]<=max){
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
//	printf("%.4f\n",ans);
}