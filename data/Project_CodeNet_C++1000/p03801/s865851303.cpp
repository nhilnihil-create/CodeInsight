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
#define mp make_pair

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
//typedef pair<int, pair<int, int> > PP;
const int MAX=1e5+10;



int main(){
	int N;
	cin>>N;
	int a[MAX];
	rep1(i,N)cin>>a[i];
	
	
	ll ans[MAX];
	rep1(i,N)ans[i]=0;
	
	priority_queue<P> q;
	rep1(i,N)q.push(mp(a[i], -i));
	q.push(mp(0,0));
	 
	P tp=q.top();
	int ni=(-1)*(tp.second);
	int tmp=tp.first;
	ll rm=tp.first;
	int nm=1;
	
	q.pop();
	while(!q.empty()){
	 	P p=q.top();
	 	q.pop();
	 	if(p.first==tmp || (-1)*p.second>ni){
		 	rm+=(ll)p.first;
		 	nm++;
		}
	 	else{
	 		ans[ni]=rm-(ll)p.first*nm;
	 		tmp=p.first;
	 		ni=(-1)*(p.second);
          	nm++;
	 		rm=(ll)nm*p.first;
	 	}
	}
	rep1(i,N)cout<<ans[i]<<endl;
}