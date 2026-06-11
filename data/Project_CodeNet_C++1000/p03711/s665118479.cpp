#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int x,y;
  	cin>>x>>y;
  	if(x==2){
     	if(y==2) cout<<"Yes"<<endl;
      	else cout<<"No"<<endl;
    }else if(x==4||x==6||x==9||x==11){
     	if(y==4||y==6||y==9||y==11) cout<<"Yes"<<endl;
      	else cout<<"No"<<endl;
    }else{
     	if(y==2||y==4||y==6||y==9||y==11) cout<<"No"<<endl;
      	else cout<<"Yes"<<endl;
    }
  	
}	