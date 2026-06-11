#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int n;
long long tmp;
bool kk[32];
bool aa[100005][32];
long long b[100005];

long long solve(int t){
	if(kk[t] == false) return 0;
	long long tt=0;
	for(int i=0;i<n;i++){
		bool add = true;
		for(int j=31;j>t;j--){
			if(!kk[j] && aa[i][j]){
				add = false;
				break;
			}
		}
		if(aa[i][t]) add = false;
		if(add) tt += b[i];
	}
	return tt;
}

int main(){
	cin>>n>>tmp;
	for(int i=0;i<32;i++){
		if(tmp%2) kk[i] = true;
		else kk[i] = false;
		tmp/=2;
	}

	for(int i=0;i<n;i++){
		cin>>tmp>>b[i];
		for(int j=0;j<32;j++){
			if(tmp%2) aa[i][j] = true;
			else aa[i][j] = false;
			tmp/=2;
		}
	}
	long long ans = 0;
	for(int i=31;i>=0;i--){
		ans = max(ans, solve(i));
	}

	long long tt=0;
	for(int i=0;i<n;i++){
		bool add = true;
		for(int j=31;j>=0;j--){
			if(!kk[j] && aa[i][j]){
				add = false;
				break;
			}
		}
		if(add) tt += b[i];
	}
	ans = max(ans,tt);
	cout<<ans<<endl;
	return 0;

}
