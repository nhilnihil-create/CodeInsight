#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
#define mp make_pair
#define pb push_back
int n;
int a[210];
int main()
{
	cin>>n;
	for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=a[2*i-1];
	cout<<ans<<endl;
}