#include<iostream>
using namespace std;
int main(){
	long long N,x;
  	long long int pos[100001];
    while(cin>>N>>x){
    	for(int i=0;i<N;i++){
        	pos[i]=0;
        }
    	long long sum=0;
    	for(int i=0;i<N;i++){
        	cin>>pos[i];
        }
      	for(int i=1;i<N;i++){
        	if(pos[i]+pos[i-1]>x){
              sum+=pos[i]-x+pos[i-1];
              if(x-pos[i-1]<0) pos[i]=0;
              else pos[i]=x-pos[i-1];
            }
        }
        cout<<sum<<endl;
    }
}