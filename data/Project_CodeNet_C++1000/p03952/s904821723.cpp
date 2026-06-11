#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
 
int main(){
	int n, x;
	cin >> n >> x;
	if(n==2){
		if(x==2){
			cout << "Yes" << endl;
			for(int i=1; i<=3; i++) cout << i << endl;
			return 0;
		}else{
			cout << "No" << endl;
			return 0;
		}
	}
 
	if(x==1 || x==2*n-1){
		cout << "No" << endl;
		return 0;
	}
 
	vector<int> v(2*n-1, 0);
	vector<bool> b(2*n, false);
	if(x!=2){
		v[n-2]=x-1; b[x-1]=true;
		v[n-1]=x; b[x]=true;
		v[n]=x+1; b[x+1]=true;
		v[n+1]=x-2; b[x-2]=true;
		int tmp=1;
		for(int i=0; i<2*n-1; i++){
			if(v[i]!=0) continue;
			while(b[tmp]) tmp++;
			v[i]=tmp;
			b[tmp]=true;
		}
	}else{
		v[n-2]=3;
		v[n-1]=2;
		v[n]=1;
		v[n+1]=4;
		for(int i=0; i<n-2; i++) v[i]=5+i;
		for(int i=n+2; i<2*n-1; i++) v[i]=i+1;
	}
 
	cout << "Yes" << endl;
	for(int i=0; i<2*n-1; i++) cout << v[i] << endl;
	return 0;
}