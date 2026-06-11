#include<iostream>
using namespace std;
const int N=502;
int ar[N];
int main(){
	int n,m,a,b,i,j;
	cin>>n>>m>>a>>b;
	if(n%a==0&&m%b==0){
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	if(n%a!=0){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i%a==1){
					cout<<69696*(a-1)-1<<' ';
				}
				else{
					cout<<-69696<<' ';
				}
			}
			cout<<"\n";
		}
	}
	else{
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(j%b==1){
					cout<<69696*(b-1)-1<<' ';
				}
				else{
					cout<<-69696<<' ';
				}
			}
			cout<<'\n';	
		}
	}
}