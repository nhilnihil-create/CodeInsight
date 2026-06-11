#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >>n;
	vector<long long> a(n);

	for(int i = 0; i < n; ++i)
		cin >>a[i];

	bool st = true;
	int dir = 0, cnt = 0;
	for(int i = 0; i < n; ++i){
		if(st){
			++cnt;
			st = false;
			if(i + 1 < n){
				if(a[i + 1] > a[i])
					dir = 1;
				else if(a[i + 1] < a[i])
					dir = 2;
				else
					dir = 0;
				continue;
			}
		}
		
		if(i + 1 == n)
			continue;

		if(dir == 1){
			if(a[i + 1] < a[i])
				st = true;
		}
		else if(dir == 2){
			if(a[i + 1] > a[i])
				st = true;
		}
		else{
			if(a[i + 1] > a[i])
				dir = 1;
			else if(a[i + 1] < a[i])
				dir = 2;
			else
				dir = 0;
		}
	}
	cout <<cnt <<'\n';
	return 0;
}
