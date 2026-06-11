#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int a[N];
int cnt[N];
int b[N]; 
bool cmp(int a,int b){    return a < b;} 
int main()
{    
	int n;
	while(cin >> n)
	{        
		memset(cnt,0,sizeof(cnt));        
		int j = 0;        
		for(int i=0; i<n; i++){	
			cin >> a[i];            
			cnt[a[i]] ++;            
			if(cnt[a[i]] == 1)                
			b[j++] = a[i];        
		}        
		if(j == 1){
			cout << n << endl;            
			continue;        
		}        
		sort(a,a+n,cmp);        
		sort(b,b+j,cmp);       
		int maxx = 0;        
		int sum = 0;        
		for(int i=a[0]; i<a[n-1]; i++){            
			sum += cnt[i] + cnt[i+1] + cnt[i+2];            
			if(maxx < sum){
				maxx = sum; 
			}                        
			sum = 0;        
		}        
		cout << maxx << endl;    
	}    
			return 0;
}
