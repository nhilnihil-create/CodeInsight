#include <iostream>
#include<string.h>
using namespace std;
string A; 
void cs()
{
	cin>>A;
	long long n=A.length();
	int *ans=new int[n+10];
	memset(ans,0,sizeof(ans));
	int i1=1,re=n,i2=0;
	for(int i=0;i<n-1;i++)
	{
		i2=i;i1=i+1;
		while(A[i2]=='S'&&A[i1]=='T')
		{
			re=re-2;ans[i2]=ans[i1]=1;
			while(ans[i2]==1&&i2>0)
			{
				i2--;
			}
			if(i2==0)
			{
				if(ans[0])
				{
					i2=i1+1;
					i1=i1+2;
				}else
				{
					i2=0;
					i1=i1+1;
				}
			}else
			{
				i1=i1+1;
			}
			i=i1-1;
		}

	}
	cout<<re<<endl;
}

int main(int argc, char** argv) 
{
    cs(); 
	return 0;
}