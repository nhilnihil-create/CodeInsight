#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>//"geometry.cpp"
#include <iomanip>//"cout<<fixed<<setprecision(n)<<sth<<endl;"
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>//"lower_bound(it,it,v)", "next_permutation(a,a+n)"
#include <functional>//"greater<T>" Ex. sort(a,a+n,greater<int>());
#include <cmath>//"abs", "sqrt"
using namespace std;
#define pb push_back
#define fi first
#define sc second
#define mp make_pair
#define is insert
typedef pair<int,int> pii;//Add other types in the same way.

bool q(long long n){
	char ans;
	cout<<"? "<<n<<endl;
	cin>>ans;
	if(ans=='Y') return true;
	else return false;
}

int main(){
	long long m=1;
	for(;m<=1000000000;m*=10){
		if(!q(m)) break;
	}
	if(m==10000000000){
		m=1;
		for(long long i=2;i<=2000000000;i*=10){
			if(q(i)) break;
			m*=10;
		}
	}else{
		long long lb=m/10,ub=m-1;
		while(ub-lb>1){
			long long mid=(lb+ub)/2;
			if(q(10*mid)){
				ub=mid;
			}else{
				lb=mid;
			}
		}
		m=ub;
	}
	cout<<"! "<<m<<endl;
	fflush(stdout);
	return 0;
}