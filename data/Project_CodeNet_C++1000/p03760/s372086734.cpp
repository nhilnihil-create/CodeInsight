#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string odd,even;
int main()
{
	cin>>odd>>even;

	string ans = "";
	int len_odd = odd.length();
	int len_even = even.length();

	int cnt_even = 0;
	for (int i = 0 ; i < len_odd ; i++)
	{
		ans+=odd[i];
		if (cnt_even < len_even) ans+=even[cnt_even++];
	}

	cout<<ans<<endl;

}