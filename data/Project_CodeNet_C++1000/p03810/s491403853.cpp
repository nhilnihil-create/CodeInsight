#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn = 101010;

int a[Maxn]={0},n;

int gcd(int x,int y)
{
	while(y)
	{
		swap(x,y);
		y%=x;
	}
	return x;
}

int calcgcd()
{
	int re = a[1];
	for(int i=2;i<=n;i++)
	{
		if(re == 1)	return 1;
		re = gcd(re,a[i]);
	}
	return re;
}

short int getans()//0: first win     1:second win
{
	int l = 0;
	bool t = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1)	l++;
		else	t^=true;
	}
	if(!t && l==1)	return -1;
	return !t;
}

bool work()//0:first lose    1:second lose
{
	for(int i=1;i<=n;i++)
	{
		if(!(a[i]&1))	continue;
		if(a[i] == 1)	return 0;
		a[i]--;
		break;
	}
	int d = calcgcd();
	if(d != 1)
		for(int i=1;i<=n;i++)	a[i] /= d;
	short int p = getans();
	if(p == -1)	return work()^1;
	return p;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	short int p = getans();
	if(p == -1)	cout<<(work() ? "First" : "Second")<<endl;
	else cout<<(p ? "Second" : "First")<<endl;
	return 0;
}