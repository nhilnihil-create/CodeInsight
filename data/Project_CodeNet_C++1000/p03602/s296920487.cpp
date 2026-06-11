#define rep(i,a,b) for(int i=a;i<b;++i)
#define repr(i,a,b) for(int i=a,i > b;--i)
#define mm(lamb, tttt) memset(lamb, tttt, sizeof lamb)

#define null NULL
#define eps 0.000000001
#define mod 1000000007
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define sz(V) (ll)V.size()
#define _ <<" "<<

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <iterator>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <limits.h>
#include <iomanip>
#include <cctype>
#include <numeric>
#include <complex>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <double, double> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<int> vii;

ll a[301][301];
bool road[301][301];
int main(){
	int n;
	cin>>n;
	rep(i,0,301) rep(j,0,301) road[i][j]=1;
	rep(i,0,n) rep(j,0,n) cin>>a[i][j];
	rep(i,0,n)
		rep(j,0,n)
			rep(k,0,n){
				if(k==j || k==i ) continue;
				if(a[i][j] > a[i][k]+a[k][j]){
					cout<<-1<<endl;
					return 0;
				}
				if(a[i][j] == a[i][k]+a[k][j]) road[i][j]=false;
			}
	ll ans=0;
	rep(i,0,n)
		rep(j,0,n){
			if(road[i][j]) ans+=a[i][j];
		}		
	cout<<ans/2<<endl;	
}

