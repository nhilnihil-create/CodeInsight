#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<char> Q;
int main()
{
	char s[200005];
	scanf("%s",s);//字符串
	int len=strlen(s);
	//printf("%d\n",len);
	for(int i=0;i<len;i++){
		if(!Q.empty()&&s[i]=='T'&&Q.back()=='S'){
			//把S拿出来
			Q.pop_back();
		}
		else
			Q.push_back(s[i]);//入数组
	}
	int cnt=0;
	while(!Q.empty()){
		Q.pop_back();
		cnt++;
	}
	printf("%d\n",cnt);
}