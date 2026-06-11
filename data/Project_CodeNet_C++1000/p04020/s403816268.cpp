/*
有一组面值为1~N的牌，已知每种面值的个数
卡牌a,b可以组成一对(a, b)当且仅当|a面值 - b面值|<=1
问最多能组多少对。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int arr[N];
signed main(){
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=2;i<=n;i++){
		if(arr[i-1]%2){
			if(arr[i]){
				arr[i-1]++;
				arr[i]--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		s+=arr[i]/2;
		if(arr[i]%2) arr[i]=1;
		else arr[i]=0;
	}
	for(int i=2;i<n;i++){
		if(arr[i]&&arr[i-1]) arr[i]=0,arr[i-1]=0,s++;
		else if(arr[i]&&arr[i+1]) arr[i]=0,arr[i+1]=0,s++;
	}
	cout<<s;
	return 0;
}

/*
3
1
2
1

*/