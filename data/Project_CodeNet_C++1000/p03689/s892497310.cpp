#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=10000;
const ll INF=1000000010;
const int MAX=100001;
int dx[8]={0,1,0,-1,1,-1,1,-1};
int dy[8]={1,0,-1,0,1,-1,-1,1};
int main(){
	int H,W,h,w;
	cin>>H>>W>>h>>w;
	if(H%h==0&&W%w==0){
		cout<<"No"<<endl;
		return 0;
	}else{
		cout<<"Yes"<<endl;
	}
	int s1=H/h*W/w*2;
	int s2=-s1*(w*h-1)-1;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(i%h||j%w){
				cout<<s1;
			}else{
				cout<<s2;
			}
			if(j==W){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}	
	return 0;
}
