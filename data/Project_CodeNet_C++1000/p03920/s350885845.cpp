//cod2016_final_b.cpp
//Sun Dec  2 19:21:41 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int total = 0;
	int ans = 0;
	int dif = 0;
	for (int i=1;i<=n;i++){
		total = total + i;
		if (total >= n){
			ans = i;
			dif = total-n;
			break;
		}
	}

	for (int i=1;i<=ans;i++){
		if (i!=dif){
			cout << i << endl;
		}
	}
}