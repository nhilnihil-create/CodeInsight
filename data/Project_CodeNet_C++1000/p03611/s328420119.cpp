#include<bits/stdc++.h>
using namespace std;
int b[1000005];

int main()
{
	
	int n;
	memset(b,0,sizeof(b));	
	cin >> n;
	int a[n],max = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		
		if(max < a[i])
			max = a[i];//求出数组里最大值，防止下面循环次数过多
		b[a[i]]++;
		b[a[i]-1]++;
		b[a[i]+1]++;
	
	}
	
	int max1 = 0;
	for(int i = 0;i <= max + 1;i++){
		if(max1 < b[i])
			max1 = b[i];
	}
	cout << max1;
	return 0;
}
