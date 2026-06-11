#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
using namespace std;
//
const int inf=1e9+7;//0x3f
//
int N;
int A[100000];
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	int now=1;
	long long ans=0;
	for(int i=0;i<N;i++){
		if(A[i]<now){
			continue;
		}else if(A[i]==now){
			now++;
		}else{
			ans+=(A[i]-1)/now;
			if(now==1){
				now++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}