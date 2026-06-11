#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(a,n) rep(i,0,n){ cout<<(i ? " ":"")<<a[i]; }cout<<endl;
int main(){
	int N;cin>>N;
	int a;map<int,int> count;
	rep(i,0,N){
		cin>>a;
		count[a]++;
	}int b=0,c=0;
	for(pair<int,int> u:count){
        b++;
		c+=u.second-1;
	}cout<<b-(c%2 ? 1 : 0)<<endl;
}