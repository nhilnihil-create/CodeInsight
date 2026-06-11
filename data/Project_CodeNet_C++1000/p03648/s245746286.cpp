#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

#define INF 1000000007ll
#define pb push_back
#define mp make_pair
#define err(x) cout<<#x<<"= "<<x<<endl;
#define rep(i,n) for(int i =0; i< n; i++)
#define ff first
#define ss second
#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define SIZE 100010

int main(){
	ios::sync_with_stdio(false);
	ll r,x,k,n;
	cin>>k;
	cout<<50<<endl;
	n= 50;
	r = k%50; x = k/50;

	rep(i,r){
		cout<<100+x-r<<' ';
	}
	rep(i,50-r){
		cout<<49+x-r<<' ';
	}
	cout<<endl;

	return 0;
}
