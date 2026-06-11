#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int n,T;//如果最多的蛋糕有n个，T是原题变量 
	cin>>n>>T;//输入 
	int k=0;//k就不用多说了吧，原题的变量 
	for(int i=1;i<=T;++i) //通过循环来尝试得出k的正确值 
	{
		int a;//要用另一个变量 
		cin>>a;//这个也是要输入的 
		k=max(k,a);//看看哪个大，把大的赋值给k 
	}
	cout<<max(k-1-(n-k),0)<<endl;//使用公式
	return 0; 
}