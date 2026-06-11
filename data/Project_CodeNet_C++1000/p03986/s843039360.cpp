#include<iostream>
#include<string.h>
using namespace std;

int main(){
	char c[200001];
	int x[200001];
	cin>>c;
	int length=strlen(c);
		for(int i=0;i<length;i++){
			if(!x[i]&&c[i]=='S'){
				for(int y=i+1;y<length;y++){
					if(!x[y]&&c[y]!='T'){
						break;
					}else if(!x[y]&&c[i]=='S'&&c[y]=='T'){
							x[i]=1;x[y]=1; 
							
							for(int n=1,m=1;n<=i&&y+m<length;){
								while(n<=i&&x[i-n]){if(x[i-n])n++;
								}
								while(y+m<length&&x[y+m])if(x[y+m])m++;
								if(!x[i-n]&&!x[y+m]&&c[i-n]=='S'&&c[y+m]=='T'){
									x[i-n]=1;x[y+m]=1;
								}else
								{
									break;
								}
							}
							break;
					}
				}
			}
		}
	int ans=0;
	for(int i=0;i<length;i++){
		if(!x[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
}