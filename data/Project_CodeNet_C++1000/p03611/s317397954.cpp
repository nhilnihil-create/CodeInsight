#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000+5];
//筒排法
//只能对每个数进行三种操作：+1，-1，或不做处理
//思路：记录每一种可能的数出现的次数，循环遍历到10000找出最大的数即为答案 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int x;
		scanf("%d",&x);
		x = x + 1;
		arr[x]++;
		arr[x - 1]++;
		arr[x + 1]++;
	}
	int max = arr[1];
	for(int i = 2;i <= 100000;i++){
		if(arr[i] >= max)
			max = arr[i];
	}
	printf("%d\n",max);
	return 0;	
} 