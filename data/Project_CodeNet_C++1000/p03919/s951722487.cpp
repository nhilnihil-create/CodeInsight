//cod2016_final_a.cpp
//Sat Oct 20 22:14:51 2018

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
	int h,w;
	cin >> h >> w;

	string a[h][w];
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			cin >> a[i][j];
			if (a[i][j] == "snuke"){
				char x = 'A';
				x = x + j;
				cout << x << i+1<<endl;
			}
		}
	}
}