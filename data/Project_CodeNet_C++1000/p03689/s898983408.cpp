#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
int fld[514][514];
signed main(){
	int H,W,h,w;
	cin>>H>>W>>h>>w;
	if( (H%h==0) && (W%w==0)){
		cout<<"No"<<endl;
		return 0;
	}
	if( H%h != 0){
		cout<<"Yes"<<endl;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(i%h == h-1){
					fld[i][j] = -1 * ( (h-1) *100000 + 1);
				}
				else{
					fld[i][j] = 100000;
				}
			}
		}
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				cout<<fld[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<"Yes"<<endl;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(j%w == w-1){
					fld[i][j] = -1 * ( (w-1) *100000 + 1);
				}
				else{
					fld[i][j] = 100000;
				}
			}
		}
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				cout<<fld[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}