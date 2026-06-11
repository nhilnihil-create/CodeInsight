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
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;


int main()
{
	int N;
	int p[20000];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> p[i];
	}
	int inv_p[20000];
	for(int i = 0; i < N; i++){
		inv_p[p[i]-1] = i+1;
	}
	
	for(int i = 0; i < N; i++){
		cout << i * N + inv_p[i];
		if(i < N-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	for(int i = 0; i < N; i++){
		cout << (N-i) * N + inv_p[i];
		if(i < N-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	
	return 0;
}