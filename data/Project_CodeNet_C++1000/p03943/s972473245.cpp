#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> in(3);
	for(int &i: in) cin >> i;
	sort(in.begin(), in.end());
	if(in[0]+in[1] == in[2]) puts("Yes");
	else puts("No");
}
