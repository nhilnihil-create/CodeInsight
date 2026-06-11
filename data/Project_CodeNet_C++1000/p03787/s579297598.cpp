#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
//cout<<setprecision(20)
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int LBI(vector<llint>&ar,llint in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
int UBI(vector<llint>&ar,llint in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	llint i,n,m;cin>>n>>m;
	vector<vector<int>>go(n);
	llint bo=0,nibu=0,ren=0;
	for(i=0;i<m;i++){
		int u,v;cin>>u>>v;u--;v--;
		go[u].pub(v);
		go[v].pub(u);
	}
	vector<int>oto(n);//音～
	for(i=0;i<n;i++){
		if(go[i].size()==0){bo++;oto[i]=1;continue;}//お布団0人
		if(oto[i]){continue;}
		ren++;
		queue<int>que;
		bool ni=true;
		oto[i]=1;que.push(i);
		while(que.size()>0){
			int ter=que.front();que.pop();
			for(auto it:go[ter]){
				if(oto[it]==oto[ter]){ni=false;}
				if(oto[it]==0){
					oto[it]=3-oto[ter];
					que.push(it);
				}
			}
		}
		if(ni){nibu++;}
	}
	cout<<2*n*bo-bo*bo+ren*ren+nibu*nibu<<endl;
	return 0;
}