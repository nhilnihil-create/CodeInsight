#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 7;
int n, candy[N];

int main(){
	cin>>n;
	for (register int i = 1;i <= n;i ++)cin>>candy[i];
	sort(candy + 1, candy + n + 1, greater<int>());
	for (register int i = 1, j;i <= n;i ++)
		if (i + 1 <= candy[i + 1])continue;
		else {
			for (j = 1;candy[i + j] == i;j ++)continue;
			if (((candy[i] - i)&1) || !(j&1))cout<<"First";
			else cout<<"Second";
			return 0;
		}
}