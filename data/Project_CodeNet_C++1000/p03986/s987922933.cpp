#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
const int maxn=2e5+10;
char str[maxn],c;
deque<char> q;
int main()
{
	int len=0;
	while((c=getchar())!='\n')
    {
    	str[len]=c;
    	len++;
	}
	q.clear();
	q.push_back('#');
	for(int i=0;i<len;i++)
	{
		if(str[i]=='S')
			q.push_back(str[i]);
		else if(str[i]=='T')
		{
			char a=q.back();
			if(a=='T'||a=='#')
				q.push_back(str[i]);
			else if(a=='S')
				q.pop_back();
		}	
	}
	int ans=q.size();
	if(ans%2==1) ans--;
	printf("%d\n",ans); 
	return 0;
}