#include<iostream>
#include<vector>
using namespace std;
int I=1000000007;
void Prime(int N,vector<int>& div){
	for(int i=2;i*i<=N;i++){
		while(N%i==0){
			div[i]++;
			N/=i;
		}
	}
	if(N!=1) div[N]++;
}
int main(){
   int N;
   cin>>N;
   vector<int> div(1001,0);
    for(int i=2;i<=N;i++){
        Prime(i,div);
        }
       
    long long int ans=1;
    for(int i=0;i<div.size();i++){
    	if(div[i]!=0){
    		ans*=(div[i]+1);
    		ans%=I;
    	}
    }
   cout<<ans<<endl;
}