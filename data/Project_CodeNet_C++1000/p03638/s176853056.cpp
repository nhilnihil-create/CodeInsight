#include <iostream>
using namespace std;

int main(){
	int h,w,n;
	cin>>h>>w>>n;
	
	int a[n+1],b[h][w],k=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=0;i<h;i++){
		if(i&1)
			for(int j=0;j<w;j++){
				if(a[k]){
					b[i][j]=k;
					a[k]--;
				}
				else{
					while(a[k]==0)
						k++;
					b[i][j]=k;
                                        a[k]--;

				}
			}
		else	
			for(int j=w-1;j>=0;j--){
				if(a[k]){
                                        b[i][j]=k;
                                        a[k]--;
				}
                                else{
                                        while(a[k]==0)
                                                k++;
                                        b[i][j]=k;
                                        a[k]--;

                                }
			}
	}
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
}	
