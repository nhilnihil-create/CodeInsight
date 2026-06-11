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

using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int cycle(int k, int P){
	if(k > P){
		return k-P;
	}else if(k <= 0){
		return k+P;
	}else{
		return k;
	}
}

int main()
{
	int N, x;
	cin >> N >> x;
	
	list<int> v;
	
	if(x <= 1 || x >= 2*N-1){
		cout << "No" << endl;
	}else{
		v.push_back(x);
		for(int i = 1; i <= N-1; i++){
			v.push_back(cycle(x + i, N*2-1));
			v.push_front(cycle(x-i, N*2-1));
		}
		
		cout << "Yes" << endl;
		for(auto itr = v.begin(); itr != v.end(); itr++){
			cout << *itr << " ";
		}
		cout << endl;
	}
	
	return 0;
}