#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e5;
LL h[N];
LL n;
LL A, B;
LL ceil_div(LL a, LL b)
{
	return a/b + (a%b==0 ? 0 : 1);
}
bool is_possible(LL kaboom)
{
	LL allocatable_kaboom = kaboom;
	for(int i = 0; i < n; i++)
		if(kaboom*B < h[i])
		{
			LL needed_kaboom = ceil_div(h[i]-kaboom*B,A-B);
			if(allocatable_kaboom >= needed_kaboom)
				allocatable_kaboom -= needed_kaboom;
			else
				return false;
		}
	return true;
}
LL bs() //find the least kaboom for which it is possible
{
	LL L = 0;
	LL R = 5e9;
	while(R-L > 10)
	{
		LL M = (L+R)/2;
		if(is_possible(M))
			R = M;
		else
			L = M;
	}
	for(LL ans = L; ans <= R; ans++)
		if(is_possible(ans))
			return ans;
	return -1;
}
int main()
{
	cin >> n >> A >> B;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	cout<<bs()<<endl;
	return 0;
}