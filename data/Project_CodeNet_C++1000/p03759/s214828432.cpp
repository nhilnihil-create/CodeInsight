#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	int i;
	for(i=1;i<=3;i++){
		cin>>a[i];
	}
	sort(a+1,a+4);
	if((a[2]-a[1])==(a[3]-a[2])){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
    return 0;
}