#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<deque>
using namespace std;
int n;
long long a[5005];
int main(){
	int n;
	long long x;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	long long mi=1e18;
	for(int i=0;i<n;i++){
		deque<int> q;
		long long res=0;
		for(int j=n-i;j<n;j++){
			while(!q.empty()&&a[q.back()]>=a[j]) q.pop_back();
			q.push_back(j);
		}
		for(int j=n;j<2*n;j++){
			while(!q.empty()&&q.front()<j-i) q.pop_front();
			while(!q.empty()&&a[q.back()]>=a[j]) q.pop_back();
			q.push_back(j);
			res+=a[q.front()];
		}
		mi=min(mi,res+x*i);
	}
	cout<<mi;
}