//agc006_b.cpp
//Sun Jul 28 19:35:16 2019

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
	int n,x;
	cin >> n >> x;

	if (x==2*n-1||x==1){
		cout << "No" << endl;
		return 0;
	}else {
		cout << "Yes" << endl;
	}

	if (n==2){
		cout << 1 << endl;
		cout << 2 << endl;
		cout << 3 << endl;
		return 0;
	}

	int num = 1;
	if (x==2*n-2){
		for (int i=0;i<n-3;i++){
			while (num>=x-2 && num<=x+1){
				num++;
			}
			cout << num << endl;
			num++;
		}
		cout << x-1 << endl;
		cout << x+1 << endl;
		cout << x << endl;
		cout << x-2 << endl;
		for (int i=n+1;i<2*n-1;i++){
			while (num>=x-2 && num<=x+1){
				num++;
			}
			cout << num << endl;
			num++;
		}
	}else {
		for (int i=0;i<n-3;i++){
			while (num>=x-1 && num <= x+2){
				num++;
			}
			cout << num << endl;
			num++;
		}
		cout << x+1 << endl;
		cout << x-1 << endl;
		cout << x << endl;
		cout << x+2 << endl;
		for (int i=n+1;i<2*n-1;i++){
			while (num>=x-1 && num <= x+2){
				num++;
			}
			cout << num << endl;
			num++;
		}
	}

}