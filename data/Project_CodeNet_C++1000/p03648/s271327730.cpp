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
//const int MAX=;



int main(){
	ll K;
	cin>>K;
	ll a[50];
	rep(i,50)a[i]=49+K/50;
	ll r=K%50;
	rep(i,r)a[i]+=51-r;
	for(int i=r;i<50;i++)a[i]-=r;
	
	cout<<50<<endl;
	rep(i,50)cout<<a[i]<<" ";
	cout<<endl;
}