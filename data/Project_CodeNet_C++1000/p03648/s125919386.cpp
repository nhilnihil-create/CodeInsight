#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>
#define LL long long
#define INF 1ll<<60
using namespace std;
const int N=2e5+100;
const int M=4e5+100;
const int mod=1e9+7;
LL arr[N];

int main() {
	LL k;

	while(cin>>k){
		
		cout<<50<<endl;
		LL tmp=k/50;
		for(int i=1;i<=50;i++)arr[i]=(LL)i+tmp-1;
		LL cnt=k%50;
		for(int i=1;i<=cnt;i++){
			
			for(int j=1;j<=50;j++){
				if(j==i){
					arr[j]+=50;
				}else{
					arr[j]-=1;
				}
			}
			
		}
		for(int i=1;i<=50;i++)cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
	
	


}
