#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int A[300][300];
int main() {
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> A[i][j];
		}
	}
	LL sum=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			bool ok=false;
			for(int k=0;k<N;k++){
				if(i==k||j==k)continue;
				if(A[i][j]>A[i][k]+A[k][j]){
					puts("-1");
					return 0;
				}
				if(A[i][j]==A[i][k]+A[k][j]){
					ok=true;
					break;
				}
			}
			if(!ok){
				sum+=A[i][j];
			}
		}
	}
	cout << sum << endl;

	return 0;
}

