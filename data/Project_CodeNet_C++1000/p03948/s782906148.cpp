//arc063_d.cpp
//Thu Jul  4 23:06:24 2019

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
	int n,t;
	cin >> n >> t;

	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}

	int tempmax = a[n-1];
	int maxdif = 0;
	int ans = 0;
	for (int i=n-2;i>=0;i--){
		if (a[i]>tempmax){
			tempmax = a[i];
		}
		if (tempmax-a[i]==maxdif){
			ans++;
		}else if (tempmax-a[i]>maxdif){
			ans = 1;
			maxdif = tempmax-a[i];
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}