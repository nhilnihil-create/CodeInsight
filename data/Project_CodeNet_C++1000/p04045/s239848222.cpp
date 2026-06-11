#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int x;
	vector<bool> av(10, true);
	for(int i = 0; i < k; i++) {
		cin>>x;
		av[x] = false;
	}

	cout<<endl;
	while(1) {
		int x = n;
		bool flag = true;
		while(x > 0) {
			int r = x%10;
			if(!av[r]) flag = false;
			x = x/10;
		}
		if(flag) break;
		n++;
	}
	cout<<n;
}
