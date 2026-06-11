#include<bits/stdc++.h>
using namespace std;
char c[200000+5];
int main()
{
//	gets(c);
	scanf("%s",c);
	int len=strlen(c);
	stack<char>ans;
	for(int i=0;i<len;++i){
		if(ans.empty()){
			ans.push(c[i]);
			continue;
		}
		if(ans.top()=='S'&&c[i]=='T'){
			ans.pop();
		}
		else{
			ans.push(c[i]);
		}
	}
	cout<<ans.size()<<endl;
	return 0;
 } 