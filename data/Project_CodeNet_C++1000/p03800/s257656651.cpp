//Menagerie
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// ÉÏ ×ó ÏÂ ÓÒ
const int N=100005,M=1000005,mod=1000000007;
const long long llinf=9223372036854775807ll;
// 1 ÏàÍ¬ 0 ²»Í¬ 
// 1 Ñò 0 ÀÇ 
// 1 ÏàÍ¬ 0 ²»Í¬ 
int n;
bool talk[N],ani[N];
void make(void)
{
	for(int i=2;i<n;i++)
	{
		bool op=1^(ani[i]^talk[i]);
		if(op==true)
			ani[i+1]=ani[i-1];
		else
			ani[i+1]=ani[i-1]^1;
	}
}
bool check(void)
{
	int op1=1^(ani[1]^talk[1]),op2=1^(ani[n]^talk[n]);
	if(op1!=(1^(ani[n]^ani[2])))
		return false;
	if(op2!=(1^(ani[1]^ani[n-1])))
		return false;
	return true;
}
void print(void)
{
	for(int i=1;i<=n;i++)
		cout<<((ani[i]==1)?'S':'W');
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if(ch=='o')
			talk[i]=true;
		else
			talk[i]=false;
	}
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		{
			ani[1]=i,ani[2]=j;
			make();
			if(check())
			{
				print();
				return 0;
			}
		}
	cout<<-1;
	return 0;
}