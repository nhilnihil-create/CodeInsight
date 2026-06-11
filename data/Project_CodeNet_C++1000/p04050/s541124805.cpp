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
#include<unordered_map>
#include<array>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
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
#define RE return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;
const llint big=1e12+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <class T> void soun(T& ar)
{sort(ar.begin(),ar.end());ar.erase(unique(ar.begin(),ar.end()),ar.end());}
llint gcd(llint a,llint b){if(a%b==0){return b;}else{return gcd(b,a%b);}}
llint lcm(llint a,llint b){return a/gcd(a,b) *b;}
int main(void){
	int i,n,m,ki=0;cin>>n>>m;
	if(n==1){cout<<1<<endl<<1<<endl<<1<<endl;RE;}
	vector<int>A(m);
	for(i=0;i<m;i++){cin>>A[i];}
	for(i=0;i<m;i++){
		if(A[i]%2==1){
			if(ki==0){swap(A[0],A[i]);ki++;}
			else {swap(A[m-1],A[i]);}
			
		}
	}
	ki=0;
	for(i=0;i<m;i++){ki+=A[i]%2;}
	if(ki>=3){cout<<"Impossible"<<endl;RE;}
	for(i=0;i<m;i++){cout<<A[i]<<" ";}
	cout<<endl;
	if(m==1){cout<<2<<endl<<n-1<<" "<<1<<endl;RE;}
	if(A[0]!=1){cout<<m<<endl;}else{cout<<m-1<<endl;}
	for(i=0;i<m;i++){
		if(i==0&&A[i]==1){}
		else if(i==0){cout<<A[i]-1<<" ";}
		else if(i==m-1){cout<<A[i]+1<<" ";}
		else{cout<<A[i]<<" ";}
	}
	return 0;
}