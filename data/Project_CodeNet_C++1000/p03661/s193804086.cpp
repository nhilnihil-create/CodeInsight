#include<iostream>
using namespace std;
	long long int Wa=0;
	long long int Sa[2];
	long long int ans=0;
	
	int a[200000];
int main(){
	int N;
	
	int i,j,k;
	            
	cin>>N;
	
	for(i=0;i<N;i++){
		cin>>a[i];
		Wa=Wa+a[i];
	}                    //////////////
	j=0;
	Sa[0]=Wa-(a[0]*2);
	if(Sa[0]<0){
		Sa[0]=0-Sa[0];
		j=-1;
	}
	ans=Sa[0];
	for(i=1;i<N-1;i++){
		if(j==0){
			Sa[1]=Sa[0]-a[i]*2;
		}else{
			Sa[1]=-Sa[0]-a[i]*2;
		}
		if(Sa[1]<0){
			Sa[1]=0-Sa[1];
			j=-1;
		}else{
			j=0;
		}
		if(ans>Sa[1]){
			ans=Sa[1];
		}
		Sa[0]=Sa[1];
	}
	
	cout<<ans<<endl;
	return 0;
}