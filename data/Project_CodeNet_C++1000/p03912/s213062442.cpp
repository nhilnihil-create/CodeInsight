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
#define dme cout<<"IMPOSSIBLE"<<endl;return 0
//ios::sync_with_stdio(false);
//std::cin.tie(0);
//<< setprecision(20)
const int mod=1e9+7;//19234567892927;
const llint mmd=1e9+7;
const int big=1e12+100;
const long double pai=3.141592653589793238462643383279502884197;
const long double ena=2.71828182845904523536;
const long double eps=1e-7;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
int main(void){
	int i,j,ans=0,n,m,mae=0;cin>>n>>m;
	vector<int>in(n);
	vector<int>ama(m);
	vector<int>pa(m);
	for(i=0;i<n;i++){cin>>in[i];}
	sort(in.begin(),in.end());
	for(i=0;i<n;i++){
		if(i!=n-1&&in[i]==in[i+1]&&mae==0){
			pa[in[i]%m]++;mae=1;
		}else{mae=0;}
		ama[in[i]%m]++;
	}
	for(i=1;i<(m+1)/2;i++){
		ans+=min(ama[i],ama[m-i]);
		if(ama[i]>ama[m-i]){ans+=min(pa[i],(ama[i]-ama[m-i])/2);}
		else{ans+=min(pa[m-i],(ama[m-i]-ama[i])/2);}
	}
	ans+=ama[0]/2;
	if(m%2==0){ans+=ama[m/2]/2;}
	cout<<ans<<endl;
	return 0;
}