#include <iostream>
#include <cstdio>
using namespace std;
char a[100005],b;
int m,n,c;
int main(){
	while((b=getchar())!='\n'){
		m++;
		a[m]=b;
	}
	for(int i=m;i>=1;i--){
		c++;
		if(a[i]=='d'){
		if(a[m-i+1]=='b'){
			n++;
		}
	}
		if(a[i]=='b'){
		if(a[m-i+1]=='d'){
			n++;
		}
	}
		if(a[i]=='p'){
		if(a[m-i+1]=='q'){
			n++;
		}
	}
		if(a[i]=='q'){
		if(a[m-i+1]=='p'){
			n++;
		}				
		}
	}
	if(n==c){
		cout<<"Yes";
	}
	else{	
	if(n!=c||m%2!=0){
		cout<<"No"; 
	}
	}
	//cout<<endl<<"c="<<c<<endl;
	//cout<<"m="<<m<<endl;
	//cout<<"n="<<n<<endl;
	return 0;
}
