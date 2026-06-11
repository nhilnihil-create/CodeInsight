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


const int L=1e5;
int m[L];
int p[L];
LL a[L];
LL r[L];
int main() {
	int N;
	cin >> N;
	LL sum=0;
	for(int i=0;i<N;i++){
		cin >> a[i];
		sum+=a[i];
	}
	int c=-1;
	LL v=0;
	for(int i=0;i<N;i++){
		if(a[i]>v){
			p[i]=c;
			v=a[i];
			c=i;
		}
	}
	map<int,LL> vs;
	for(int i=N-1;i>0;i--){
		vs[a[i]]++;
		if(c==i){
			c=p[i];
			while(vs.size()){
				auto it=vs.end();
				it--;
				auto w=it->second;
				if(it->first>a[c]){
					auto d=it->first-a[c];
					vs.erase(it);
					vs[a[c]]+=w;
					r[i]+=w*d;
					sum-=w*d;
				}
				else{
					break;
				}
			}
		}
	}
	r[0]=sum;
	for(int i=0;i<N;i++){
		cout << r[i] << endl;
	}

	return 0;
}

