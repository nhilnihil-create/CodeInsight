#include <cstdio>
#include <string.h>
#include <algorithm>
#include<iostream>
#include<math.h>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;
#define maxn 105
int clr[10005];
int a[maxn][maxn];

int main(){
	int h,w,n;
	
	cin>>h>>w>>n;
	for(int i=1;i<n+1;i++)
		cin>>clr[i];
		
	memset(a,0,sizeof(a));
	int k=1,t=1,x=0,y=w-1;
	while(!clr[k]) k++;
	a[x][y] = k;
	clr[k]--;
	
	while(k<h*w){
		
		while(x+1<h && !a[x+1][y]){
			k++; 
			if(clr[t] == 0) t++;
			a[++x][y]=t;
			clr[t]--;
		}
		while(y-1>=0 && !a[x][y-1]){
			k++;
			if(clr[t] == 0) t++;
			a[x][--y]=t;
			clr[t]--;
		}
		while(x-1>=0 && !a[x-1][y]){
			k++;
			if(clr[t] == 0) t++;
			a[--x][y]=t;
			clr[t]--;
			
		}
		while(y+1<w && !a[x][y+1]){
			k++;
			if(clr[t] == 0) t++;
			a[x][++y]=t;
			clr[t]--;
		}
    }
    
    for(int i=0;i<h;i++){
    	cout<<a[i][0];
    	for(int j=1;j<w;j++)
    		cout<<" "<<a[i][j]; 
		cout<<endl;
	}
	return 0;
}