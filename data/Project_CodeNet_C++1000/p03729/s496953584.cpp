#include <stdio.h>
#include <string.h>

int main(){
	char arr1[101];
	char arr2[101];
	char arr3[101];
	
	scanf ("%s %s %s", &arr1, &arr2, &arr3);
		if (arr1[(strlen(arr1)-1)] == arr2[0] && arr2[(strlen(arr2)-1)] == arr3[0]){
			printf ("YES");
		}
		else {
			printf ("NO");
		}
	return 0;
}