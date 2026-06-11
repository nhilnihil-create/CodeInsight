#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,d;
char s[4]={'R','Y','B','G'};
int main(){
	cin>>n>>m>>d;
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			x=(i+j)/d,y=(i-j+m+n)/d;
			putchar(s[(x&1)*2+(y&1)]);
		}
		cout<<endl;
	}
}