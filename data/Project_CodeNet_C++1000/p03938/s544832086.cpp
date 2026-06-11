#include<bits/stdc++.h>

using namespace std;


int main(){
   int n  ;
   cin >> n  ;
  
  int p[20010],a[20010],b[20010];
  
  for(int i=1;i<=n;i++)
    cin >> p[i];
  
  for(int i=1;i<=n;i++)
		a[i]=1+30000*(i-1),b[i]=1+30000*(n-i);
  
  for(int i=1;i<=n;i++){
    a[p[i]] += i;
  }
  
  for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
  
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
}
  
  
  
