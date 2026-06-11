#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int a,b,s=1;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {  
      	if(i<0)s*=-1;
      	if(i==0){
	  		cout<<"Zero"<<endl;
			return 0;
		}
    }
    if(s>0)cout<<"Positive"<<endl;
    if(s<0)cout<<"Negative"<<endl;
    if(s==0)cout<<"Zero"<<endl;
    return 0;
}