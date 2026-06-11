#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;cin>>n>>m;
  vector<int >a(n,0),b(n,0),c(m,0),d(m,0);
  for(int i=0;i<n;i++)cin>>a[i]>>b[i];
  for(int i=0;i<m;i++)cin>>c[i]>>d[i];
  for(int i=0;i<n;i++){
  	int index = 0;
    int mini = abs(a[i]-c[0])+abs(b[i]-d[0]);
  		for(int j=1;j<m;j++){
        	if(abs(a[i]-c[j])+abs(b[i]-d[j])<mini){
            	mini = abs(a[i]-c[j])+abs(b[i]-d[j]);
              index = j;
            
            }
        
        }
    cout<<index+1<<'\n';
  }
}