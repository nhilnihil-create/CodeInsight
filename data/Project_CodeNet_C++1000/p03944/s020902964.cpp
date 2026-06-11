#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int W,H,N;
  	cin>>W>>H>>N;
  	int minx=0; int maxx=W;
  	int miny=0; int maxy=H;
  
  	rep(i,N){
      	int x,y,a;
      	cin>>x>>y>>a;
      	if(a==1) minx=max(x,minx);
      	if(a==2) maxx=min(x,maxx);
      	if(a==3) miny=max(y,miny);
      	if(a==4) maxy=min(y,maxy);
      
    }	
  	
  	if(maxx<minx) maxx=minx;
  	if(maxy<miny) maxy=miny;
  	
  	cout<<(maxx-minx)*(maxy-miny)<<endl;
  	
}