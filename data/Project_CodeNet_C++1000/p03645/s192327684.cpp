#include <bits/stdc++.h>
        using namespace std;
        int main(){
			long long n,m,a[200005],b[200005],c[200005]={};
			cin>>n>>m;
			for(int i=0;i<m;i++){
				cin>>a[i]>>b[i];
				if(b[i]==n){
					c[a[i]]=1;
					
				}
			}
			for(int i=0;i<m;i++){
				if(a[i]==1){
                    if(c[b[i]]==1){
					cout<<"POSSIBLE"<<endl;
					return(0);
                  }
                }
            }
			cout<<"IMPOSSIBLE"<<endl;
    		return(0);
        }