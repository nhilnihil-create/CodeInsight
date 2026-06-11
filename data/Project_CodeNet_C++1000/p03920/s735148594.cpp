#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
	int n;
	cin>>n;
	int cnt=0,pnt=1;
	while(true){
		if(cnt>=n)break;
		cnt+=pnt;
		pnt++;
	}
	for(int i=1;i<pnt;i++){
		if(cnt-i==n)continue;
		cout<<i<<endl;
	}
	return 0;
}
