#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<chrono>
#include<functional>
#include<random>
#include<unordered_set>
using namespace std;
typedef long long int llint;
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
const int mod=1000000007;
const int big=1e16+10;
const long double pai=3.141592653589793238462643383279;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(b==0){return a;}return gcd(b,a%b);}//a>b
llint lcm(llint a,llint b){return (a/gcd(max(a,b),min(a,b)))*b;}
int main(void){
	llint bmax=1e10,bmin=1e9,gen;
	cout<<"? "<<bmin<<endl;char C;
	cin>>C;
	if(C=='Y'){
		bmax=1e9;//なんかバグらせそう
	}else{
		while(bmax-bmin!=1){
		//ここで自書式順序を示すはず
		gen=(bmax+bmin)/2;
		cout<<"? "<<gen<<endl;
		char c;
		cin>>c;
		if(c=='Y'){bmax=gen;}
		else{bmin=gen;}
		}
	}
	//bmax,bmax/10,bmax/100...
	llint ans=bmax;
	while(-1){
		if(ans/10==0){cout<<"! "<<ans<<endl;return 0;}
		cout<<"? "<<(ans/10)+1<<endl;
		char ch;cin>>ch;
		if((ch=='N')==((to_string((ans/10)+1)).size()==to_string(ans/10).size())){cout<<"! "<<ans<<endl;return 0;}
		ans/=10;
	}
	return 0;
}