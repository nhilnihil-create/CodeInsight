#include<iostream> 
using namespace std;
char a[16];
char b[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
//b数组的值也可以是{67,79,68,69,70,69,83,84,73,86,65,76,50,48,49,54}；即这些字符的ASCII值； 
int cnt=0;//计数器 
int main()
{
    for(int i=0;i<16;i++)
    {
    	cin>>a[i];//输入 
	}
	for(int i=0;i<16;i++)
	{
		if(a[i]!=b[i])//比较：如果不一样，计数器就加1； 
			cnt++;
	}
	cout<<cnt;//输出计数器的值； 
	return 0;//养成一个好习惯； 
}