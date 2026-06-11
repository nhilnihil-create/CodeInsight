#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f[200009],lef,rig,mid,pas;
bool bo[200009];
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	a=a*2-1;
	for(b=1; b<=a; b++) cin>>f[b];
	lef=0;
	rig=a+1;
	while(1){
		if(lef+1>=rig) break;
		mid=(lef+rig)/2;
		//cout<<mid<<endl;
		for(b=1; b<=a; b++) bo[b]=!(f[b]<mid);
		if(bo[a/2+1]==bo[a/2]||bo[a/2+1]==bo[a/2+2]){
			if(bo[a/2+1]==0){
				rig=mid;
			}else{
				lef=mid;
				pas=mid;
			}
			continue;
		}
		c=0;
		for(b=2; b<=a; b++){
			if(bo[b]==bo[b-1]){
				c=1;
				break;
			}
		}
		d=0;
		if(c==0){
			if((a+1)/2%2==0){
				d=!bo[a/2+1];
			}else{
				d=bo[a/2+1];
			}
			if(d==0){
				rig=mid;
			}else{
				lef=mid;
				pas=mid;
			}
		}else{
			c=a+4;
			d=0;
			for(b=2; b<=a/2+1; b++){
				if(bo[b]==bo[b-1]){
					c=a/2+1-b;
					d=bo[b];
				}
			}
			for(b=a-1; b>=a/2+1; b--){
				if(bo[b]==bo[b+1]){
					if(b-a/2-1<c){
						c=b-a/2-1;
						d=bo[b];
					}
				}
			}
			if(d==0){
				rig=mid;
			}else{
				lef=mid;
				pas=mid;
			}
		}
	}
	cout<<pas;
	return 0;
}