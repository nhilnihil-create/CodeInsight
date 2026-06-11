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

const int S=1e5;
LL X[S];
int W[S];
vector<int> ps[2];
vector<int> xs[2];
LL N,L;
int f(LL T, LL s)
{
	//cerr << T << ", " << s << endl;
	if(ps[0].size()==0||ps[1].size()==0){
		return 0;
	}
	int f=0;
	int a;
	int b;
	if(W[s]==1){
		a=lower_bound(ps[0].begin(),ps[0].end(),s)-ps[0].begin();
		b=(lower_bound(xs[1].begin(),xs[1].end(),X[s])-xs[1].begin())%xs[1].size();
	}
	else
	{
		f=1;
		a=lower_bound(ps[1].begin(),ps[1].end(),s)-ps[1].begin();
		b=(lower_bound(xs[0].begin(),xs[0].end(),X[s])-xs[0].begin()+xs[0].size()-1)%ps[0].size();
	}
	//cerr << "aaa " << a << ", " << b << endl;
	LL c=0;
	int sg[2]={1,-1};
	while(c<T){
		//cerr << f << ", " << a << ", " << b << ": " << ps[f].size() << ", " << ps[f^1].size() << endl;
		LL p=sg[f]*c+X[ps[f][a]];
		LL q=sg[f^1]*c+X[ps[f^1][b]];
		p%=L;
		if(p<0){
			p+=L;
		}
		q%=L;
		if(q<0){
			q+=L;
		}
		if(f==0&&q<=p){
			q+=L;
		}
		else if(f==1&&p<=q){
			p+=L;
		}
		if(abs(p-q)/2+c<T){
			c+=abs(p-q)/2;
			int t=(ps[f].size()+sg[f^1]+a)%ps[f].size();
			a=b;
			b=t;
			f^=1;
		}
		else{
			break;
		}
	}
	return ps[f][a];
}
P od[S];
int main() {
	LL T;
	cin >> N >> L >> T;
	L*=2;
	T*=2;
	for(int i=0;i<N;i++){
		cin >> X[i] >> W[i];
		X[i]*=2;
		if(W[i]==1){
			ps[0].push_back(i);
			xs[0].push_back(X[i]);
		}
		else{
			ps[1].push_back(i);
			xs[1].push_back(X[i]);
		}
	}
	LL o=f(T%L,(T/L*f(L,0))%N)%N;
	for(int i=0;i<N;i++){
		LL v=X[i];
		if(W[i]==1){
			v+=T;
		}
		else{
			v-=T;
		}
		v%=L;
		if(v<0){
			v+=L;
		}
		od[i]=P(v/2,W[i]);
	}
	P key=od[o];
	sort(od,od+N);
	int s=lower_bound(od,od+N,key)-od;
	for(int i=0;i<N;i++){
		cout << od[(s+i)%N].first << endl;
	}

	return 0;
}

