#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <set>
#include <string>
#include <sstream>
#include<map>
#include <vector>
#define maxn 100000+15
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[maxn];
	int b[maxn];
	int j=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			b[j++]=i;
		}
	}
	int swp=0;
	for(int i=0;i<j;i++){
		if(a[b[i]]==b[i]){
			if(b[i]+1!=n-1){
				int x=a[b[i]];
				a[b[i]]=a[b[i]+1];
				a[b[i]+1]=x;
			}
			swp++; 
		}
	}
	cout<<swp<<endl;
	
}