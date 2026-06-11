#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
	char num[1010];
	scanf("%s",num);
	
	int i,j,flag=1;
	
	for(i=0,j=strlen(num)-1;i<strlen(num)/2;i++,j--)
	{
		if(num[i] == num[j] && i<=j){
		//	cout << num [i] << num[j] << endl;
			flag = 1;
		}  
		else{
			flag = 0;
			break;
		}
	}
//	cout << "Flag:  " << flag << endl;
	if(flag == 1) cout << "Yes\n";
	else cout << "No\n";
}