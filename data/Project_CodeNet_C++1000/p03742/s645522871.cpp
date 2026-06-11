#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);i++)
#define urep(i,a,n) for(ll i = (a);i>=(n);i--)
#define all(x) (x).begin(),(x).end()
#define INF 1e30
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N,X,Y;
ll ans;
ll a[1000000];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}

int main() {
	cin>>X>>Y;
	if(abs(X-Y)<=1)cout<<"Brown"<<endl;
	else cout<<"Alice"<<endl;
	return 0;
}