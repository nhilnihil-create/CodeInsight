#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    int sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
	string ans;
	int dx = tx-sx,dy=ty-sy;
	cout<<string(dx,'R')<<string(dy,'U');
	cout<<string(dx,'L')<<string(dy,'D');
	cout<<'D'<<string(dx+1,'R')<<string(dy+1,'U')<<'L';
	cout<<'U'<<string(dx+1,'L')<<string(dy+1,'D')<<'R'<<endl;
}