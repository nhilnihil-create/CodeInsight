#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a%c){
		puts("Yes");
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if(j) cout<<" ";
				if(i%c==c-1) cout<<-1000*(c-1)-1;
				else cout<<1000;
			}
			cout<<endl;
		}
	}
	else if(b%d){
		puts("Yes");
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if(j) cout<<" ";
				if(j%d==d-1) cout<<-1000*(d-1)-1;
				else cout<<1000;
			}
			cout<<endl;
		}
	}
	else puts("No");
	return 0;
}
