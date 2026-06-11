#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin>>n>>x;
	if(n==2){
		if(x==2){
			cout<<"Yes"<<endl;
			cout<<1<<endl<<2<<endl<<3<<endl;
		}
		else 
			cout<<"No"<<endl;
	}
	else{
		if(x==1||x==2*n-1)
			cout<<"No"<<endl;
		else{
			cout<<"Yes"<<endl;
			vector<int> v(2*n);
			int y=x+n;
			if(y>2*n-1)	y-=2*n-1;
			for(int i=1;i<=2*n-1;i++){
				v[i]=y;
				y=y%(2*n-1)+1;
			}
			for(int i=1;i<=2*n-1;i++)
				cout<<v[i]<<'\n';
		}
	}
}

