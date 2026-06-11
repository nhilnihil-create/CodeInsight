#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
const int MAX=1e5+5;
const lli MOD=1e9+7;

lli ct[10];

int main(){
	lli H,W;
	int N;
	cin>>H>>W>>N;
	multiset<lli> s;
	rep(o,N){
		int a,b;
		cin>>a>>b;
      	a--;
      	b--;
		rep(i,3)rep(j,3){
			if(0<=(a-i)&&(a-i)<=H-3&&0<=(b-j)&&(b-j)<=W-3){
				lli t=(a-i)*MOD+(b-j);
				s.insert(t);
			}
		}
	}

	while(!s.empty()){
		int a=(int)s.erase(*s.begin());
		ct[a]++;
	}
	lli sum=0;
	rep1(i,9)sum+=ct[i];
	ct[0]=(H-2)*(W-2)-sum;
	rep(i,10)cout<<ct[i]<<endl;
}