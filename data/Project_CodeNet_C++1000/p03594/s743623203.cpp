/*input
4 4 2
*/
#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long a[505][505],n,h,w;
void show(){
	for(int i=0;i<h;++i,cout<<'\n')
		for(int j=0;j<w;++j)
			if(a[i][j]==1) cout<<'R';
			else if(a[i][j]==2) cout<<'Y';
			else if(a[i][j]==3) cout<<'G';
			else if(a[i][j]==0) cout<<'B';
}
int main(){
	long long d,p,x=0,y=0,dx=0,dy=0,xx=0,yy=0;
	cin>>h>>w>>d;
	if(d%2){
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j)
				a[i][j]=(i+j)%2;
		}
	}
	else{
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				if(((i+j)/d)%2){
					a[i][j]=2;
				}
				if(((i-j+w)/d)%2)
					a[i][j]++;
			}
		}
	}
	show();
}