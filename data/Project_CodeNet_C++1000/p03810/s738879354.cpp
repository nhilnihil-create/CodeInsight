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
const llint mod=1000000007;//ここを変えるとよい 
const llint big=1e17+10;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=0.0000000001;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int LBI(vector<lldo>&ar,lldo in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
int UBI(vector<lldo>&ar,lldo in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	int i,n;cin>>n;
	if(n==1){cout<<"Second"<<endl;return 0;}//A[0]=1なので
	vector<llint>a(n);
	for(i=0;i<n;i++){cin>>a[i];}
	
	int flip=0;
	while(-1){
		int ki=0;
		llint sum=0;
		for(i=0;i<n;i++){
			sum+=a[i]-1;
			if(a[i]%2==1){ki++;}
			if(a[i]==1){ki++;}
		}
		if(ki>=2||sum%2==1){cout<<((flip+sum+1)%2==0?"First":"Second")<<endl;break;}
		flip++;
		for(i=0;i<n;i++){if(a[i]%2==1){a[i]--;}}
		llint koya=a[0];
		for(i=1;i<n;i++){koya=gcd(koya,a[i]);}
		//cerr<<koya<<endl;
		for(i=0;i<n;i++){a[i]/=koya;}
	}
	return 0;
}