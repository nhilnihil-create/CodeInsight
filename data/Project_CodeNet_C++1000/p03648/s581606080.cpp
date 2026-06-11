#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"

#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
typedef long long ll;
using namespace std;

ll k,p;
ll a[50];
int main() {
	cin>>k;
	rep(50)
		a[i]=49+k/50;
	p=0;
	rep(k%50){
		REP(50,j){
			if(j==p)a[j]+=50;
			else --a[j];
		}
		++p;
		p%=50;
	}
	cout<<50<<endl;
	rep(50)
		cout<<a[i]<<sp;
	cout<<endl;
	return 0;
}
