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

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

bool f(){
	int N;
	cin >> N;
	vector<int> revx(N*N+1);
	vector<int> xs(1+N);
	vector<int> buf0;
	vector<int> buf1;
	for(int i=1;i<=N;i++){
		int x;
		cin >> x;
		if(revx[x]){
			return false;
		}
		revx[x]=i;
		xs[i]=x;
	}
	for(int x=N*N;x>=1;x--){
		if(revx[x]){
			for(int i=1;i<revx[x];i++){
				buf0.push_back(revx[x]);
			}
			for(int i=revx[x]+1;i<=N;i++){
				buf1.push_back(revx[x]);
			}
		}
	}

	vector<int> ret;
	for(int x=1;x<=N*N;x++){
		if(revx[x]){
			ret.push_back(revx[x]);
		}
		else if(buf0.size()){
			int i=buf0.back();
			if(xs[i]<x){
				return false;
			}
			buf0.pop_back();
			ret.push_back(i);
		}
		else if(buf1.size()){
			int i=buf1.back();
			if(x<xs[i]){
				return false;
			}
			buf1.pop_back();
			ret.push_back(i);
		}
	}
	cout << "Yes" << endl;
	auto sp="";
	for(int r:ret){
		cout << sp << r;
		sp=" ";
	}
	cout << endl;

	return true;
}
int main() {
	if(!f()){
		cout << "No" << endl;
	}
}

