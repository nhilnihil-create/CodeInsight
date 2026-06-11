#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%i",&n);
	vector<int> a(n*2);
	for(int &i:a)scanf("%i",&i);
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=0;i<2*n;i+=2)ans+=a[i];
	printf("%i\n",ans);
	return 0;
}