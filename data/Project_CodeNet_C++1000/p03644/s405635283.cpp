#include<bits/stdc++.h>
using namespace std;

void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main()
{
	ll();
long long n;
cin>>n;
int i=1;
while(i*2<=n)
{
	i*=2;
}
cout<<i<<endl;
}
