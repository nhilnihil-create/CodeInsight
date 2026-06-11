#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int x[501];
	map<int, int> xmp;
	for(int i=1; i<=n; i++){
		scanf("%d", &x[i]);
		xmp[x[i]]=i;
	}
	deque<int> a1, a2;
	vector<int> a;
	for(auto itr=xmp.begin(); itr!=xmp.end(); itr++){
		int x=itr->first;
		int i=itr->second;
		for(int j=0; j<i-1; j++){
			a1.push_back(i);
		}
		for(int j=0; j<n-i; j++){
			a2.push_back(i);
		}
	}
	for(int j=0; j<n*(n-1)/2; j++){
		a1.push_back(a2.front());
		a2.pop_front();
	}
	for(int i=1; i<=n*n; i++){
		auto itr=xmp.find(i);
		if(itr==xmp.end()){
			a.push_back(a1.front());
			a1.pop_front();
		}else{
			a.push_back(itr->second);
		}
	}
	for(int i=1; i<=n; i++){
		int count=0;
		for(int j=0; j<n*n; j++){
			if(a[j]==i){
				count++;
				if(count==i && j+1!=x[i]){
					printf("%s\n", "No");
					return 0;
				}
			}
		}
	}
	printf("%s\n", "Yes");
	for(int i=0; i<n*n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}