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
typedef long double ld;
//const int MAX=;
//const long double INF=;


int main(){
	ll N, X;
	cin>>N>>X;
	
	ll ans=N;
	ll a=X, b=N-X;
	while(true){
		if(a>b){
			if(a%b==0){
				ans+=2*a-b;
				break;
			}
			else{
				ans+=2*(a/b)*b;
				a=a%b;
			}
		}
		else if(a==b){
			ans+=a;
			break;
		}
		else{
			if(b%a==0){
				ans+=2*b-a;
				break;
			}
			else{
				ans+=2*(b/a)*a;
				b=b%a;
			}
		}
	}
	cout<<ans<<endl;
}