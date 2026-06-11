#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#define fi first
#define se second
#define fcout(n) cout<<fixed<<setprecision((n))
#define cinl(str) getline(cin,(str))
using namespace std;
bool value(int y,int x,int R,int C){return 0<=y&&y<R&&0<=x&&x<C;}
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
double pie=acos(-1);
int INF=1000000007;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };


int main() {
	long long n;
	long long k,ex,sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		sum+=i;
		if(sum==n){
			k=i;
			ex=0;
			break;
		}
		if(sum>n){
			k=i;
			ex=sum-n;
			break;
		}
	}
	for(long long i=1;i<=k;i++){
		if(i!=ex){
			cout<<i<<endl;
		}
	}
}
