#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<tuple>
#include<utility>
#include<set>
#include<queue>
#include<iomanip>
#include<iterator>
//#include<chrono>
#include<random>
using namespace std;
typedef long long int llint;
const int big=1e9+100000;
const int mod=1e9+7;
const long double pai=3.141592653589793238462643;
#define mt make_tuple
#define mp make_pair
#define fir first
#define sec second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define res resize
#define ins insert
#define era erase
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
int main(void){
	llint n,a,ans=0,ka=1;
	cin>>n;
	while(n--){
		cin>>a;
		if(a==ka){ka++;continue;}
		ans+=(a-1)/ka;
		if(ka==1){ka++;}
	}
	cout<<ans<<endl;
	return 0;
}