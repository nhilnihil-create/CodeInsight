#include<bits/stdc++.h>
using namespace std;

 //d[u][v]は辺=(u,v)のコスト（存在しない場合はinf,ただしd[i][i]=0）


int main (){
	int n;cin>>n;
	int a[n+5][n+5],b[n+5][n+5];
	int t;
	
	for(int i=0;i<n;i++){
            		for(int j=0;j<n;j++){
            			b[i][j] = 0;	
            		
           			}
            }
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}

	for(int k=0;k<n;k++){
            	for(int i=0;i<n;i++){
            		for(int j=0;j<n;j++){
            			t = a[i][k] + a[k][j];
            			
            			if(a[i][j]>t){
            				cout<<-1<<endl;
            				return 0;
            			}
            			
            			else if(a[i][j] == t && k != i && k != j) {
            				b[i][j]=1;
            			
            			}
            		}
            	}
	}
	long long int ans = 0;
	for(int i=0;i<n;i++){
            		for(int j=0;j<n;j++){
            			if(i>=j) continue;
            			ans += a[i][j] * !b[i][j];	
            		
           			}
            }
            cout<<ans<<endl;
            
}
