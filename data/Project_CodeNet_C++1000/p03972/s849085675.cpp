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
const int INF=1e9;



int main(){
	int W,H;
	cin>>W>>H;
	vi p(W,0);
	vi q(H,0);
	rep(i,W)cin>>p[i];
	rep(i,H)cin>>q[i];
	sort(p.begin(),p.end());
	sort(q.begin(),q.end());
	p.push_back(INF);
	q.push_back(INF);
	
	int pin=0;
	int qin=0;
	int pml=H+1;
	int qml=W+1;
	ll ans=0;
	while(pin<W || qin<H){
		if(p[pin]<q[qin]){
				ans=ans+(ll)p[pin]*pml;
				pin++;
				qml--;
		}
		else{
			ans=ans+(ll)q[qin]*qml;
			qin++;
			pml--;
		} 
	}
	cout<<ans<<endl;
}