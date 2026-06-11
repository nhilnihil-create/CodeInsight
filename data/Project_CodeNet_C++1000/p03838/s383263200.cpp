#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	ll x,y;
  	cin>>x>>y;
  	ll count=0;
  	if(x>=0 && y>=0){
     	 if(x<=y) count=y-x;
      	 else if(y!=0) count=x-y+2;
      	 else count=x-y+1;
    }else if(x<0 && y<0){
    	if(x<=y) count=y-x; 
        else count=x-y+2;
    }else{
     	count=abs(x+y)+(x&&y);  
      	if(x==0 && y<0) count++;
    }
  	cout<<count<<endl;
}