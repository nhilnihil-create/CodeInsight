//arc070_c.cpp
//Fri Nov  2 22:42:16 2018

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
	int x;
	cin >> x;

	int pos = 0;
	int jikoku = 1;
	while (pos < x){
		pos += jikoku;
		jikoku++;
	}


	cout << jikoku -1 << endl;

}