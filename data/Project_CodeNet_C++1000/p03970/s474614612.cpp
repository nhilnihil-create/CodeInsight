#include<bits/stdc++.h>
using namespace std;
char st[16]={'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'};
char ss[16];
int sum;
int main(){
	cin>>ss;
	for(int i=0;i<16;i++){
		if(ss[i]!=st[i]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}