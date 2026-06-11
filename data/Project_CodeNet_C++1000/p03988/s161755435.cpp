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
//typedef pair<int, int> P;
//typedef pair<int, pair<int, int> > PP;
//const int MAX=;
int main(){
	int N;
	cin>>N;
	int ct[100];
  	rep(i,100)ct[i]=0;
	rep(_,N){
		int a;
		cin>>a;
		ct[a]++;
	}
	int l=1,r=99;
	while(true){
		if(ct[l]>0)break;
		l++;
	}
	while(true){
		if(ct[r]>0)break;
		r--;
	}
	
  	bool ans=true;
	if(r==2*l){
      	if(ct[l]!=1)ans=false;
		for(int i=l+1; i<=r; i++)if(ct[i]<2)ans=false;
	}
	else if(r==2*l-1){
		if(ct[l]!=2)ans=false;
		for(int i=l+1; i<=r; i++)if(ct[i]<2)ans=false;
	}
	else ans=false;
  
	if(ans)cout<<"Possible";
	else cout<<"Impossible";
}