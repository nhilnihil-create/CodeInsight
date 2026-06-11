#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char str[200000 + 10];
int main() {
	scanf("%s", str);
	int len = strlen(str);
	int pos = 0,p=0;
	int num_t = 0,num_s=0;
	for (int i = 0;i < len;i++) {
		if (str[i] == 'S') num_s++;
		else if (num_s) {
			num_s--;
			p++;
		}
	}
	printf("%d", len-2*p);
	return 0;
}