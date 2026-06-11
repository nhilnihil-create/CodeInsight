#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+100;
int arr[N];
int main() {
    LL n;
    while(cin>>n){
    	LL tmp=2*n;
    	tmp=sqrt(tmp);
    	for(LL i=tmp+1;;i++){
    		if(i*(i-1)>=2*n){
    			cout<<i-1<<endl;
    			break;
			}
		}
    	
	}
	return 0;
}
