#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int arr[10];
	
	for (int a=0;a<3;a++){
		scanf ("%d",&arr[a]);
	}
	
	sort(arr,arr+3);
	
	printf ("%d\n",arr[0]+arr[1]);
	
	return 0;	
}
