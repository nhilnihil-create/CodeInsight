#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef pair<int,int> P1;
typedef pair<int,P1> P2;
const int inf=1000000000;


int main() {
	int n,t;
	cin>>n>>t;
	int a[100002]={};
	int ma[100002]={};

	for(int i=1;i<n+1;i++)cin>>a[i];
	for(int i=n;i>0;--i){
		ma[i]=max(ma[i+1],a[i]);
	}
	int s=0;
	int d=0;
	for(int i=1;i<n+1;++i){
		if(d<(ma[i]-a[i])){
			s=1;
			d=ma[i]-a[i];
		}else if(d==(ma[i]-a[i])){
			s++;
		}
//		cout<<s<<endl;
	}
	cout<<s<<endl;
	return 0;
}
