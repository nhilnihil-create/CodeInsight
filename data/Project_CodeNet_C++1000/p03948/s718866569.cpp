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
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=1e5+5;

int main(){
	int N,T;
	cin>>N>>T;
	int A[MAX];
	rep(i,N)cin>>A[i];
	
	int nm=A[0];
	int dm=0;
	int p=0;
	rep1(i,N){
		nm=min(nm,A[i]);
		if(dm==A[i]-nm){
			p++;
		}
		else if(dm<A[i]-nm){
			dm=A[i]-nm;
			p=1;
		}
	}
	cout<<p<<endl;
}
