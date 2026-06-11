//agc007_b.cpp
//Sun Jul 28 21:30:18 2019

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
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n],b[n];
	for (int i=0;i<n;i++){
		a[i] = 1+40000*i;
		b[i] = 40000*(n-1)+1-40000*i;
	}

	int rank = 1;
	for (int i=0;i<n;i++){
		int p;
		cin >> p;
		p--;
		a[p] += rank;
		rank++;
	}

	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	printf("\n");
	for (int i=0;i<n;i++){
		cout << b[i] << " ";
	}
	printf("\n");
//	printf("%.4f\n",ans);
}