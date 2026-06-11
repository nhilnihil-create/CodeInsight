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

int N;
lli A,B;
lli h[MAX];

bool er(lli k){
	lli p[MAX];
	lli ex=0;
	rep(i,N){
		p[i]=max((lli)0,h[i]-B*k);
		if(p[i]!=0)p[i]=(p[i]-1)/(A-B)+1;
		ex+=p[i];
	}
	if(ex<=k)return true;
	else return false;
}

int main(){
	cin>>N>>A>>B;
	rep(i,N)cin>>h[i];

	int lb=-1, ub=1e9;
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(er(mid))ub=mid;
		else lb=mid;
	}
	cout<<ub;
}