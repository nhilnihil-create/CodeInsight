#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
bool flag[200001];
int main()
{
	memset(flag,0,sizeof(flag));
	string c;
	cin>>c;
	int size=c.size();
	for(int i=0;i<size;i++)
	{
		if(!flag[i]&&c[i]=='S')
		{
			for(int j=i+1;j<size;j++)
			{
				if(!flag[j]&&c[j]!='T')
				{
					break;
				}
				else if(!flag[j]&&c[i]=='S'&&c[j]=='T')
				{
					flag[i]=1;flag[j]=1;
					for(int n=1,m=1;n<=i&&j+m<size;)
					{
						while(n<=i&&flag[i-n])
							if(flag[i-n])n++;
						while(j+m<size&&flag[j+m])
							if(flag[j+m])m++;
						if(!flag[i-n]&&!flag[j+m]&&c[i-n]=='S'&&c[j+m]=='T')
						{
							flag[i-n]=1;flag[j+m]=1;
						}
						else
						{
							break;
						}
					}
					break;
				}
			}
		}
	}
	int count=0;
	for(int i=0;i<size;i++)
	{
		
		if(!flag[i]){
			count++;
		}
	}
	cout<<count<<endl;
}
