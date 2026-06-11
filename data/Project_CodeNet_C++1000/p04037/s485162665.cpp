#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn=1e5+10;

int a[maxn];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int pos=0;
	for(int i=1;i<=n;++i){
		if(a[i]>=i && a[i+1]<=i){
			pos=i;
			break;
		}
	}
	int len1=0;
	for(int i=pos+1;i<=n;++i){
		if(a[i]>=pos) len1++;
	}
	int len2=a[pos]-pos;
	if((!(len1&1)) && (!(len2&1))) cout<<"Second\n";
	else cout<<"First\n";
} 