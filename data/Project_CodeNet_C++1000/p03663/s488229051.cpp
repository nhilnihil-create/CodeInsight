#include<bits/stdc++.h>
using namespace std;
long long w=10;
int n;
int ans=0;
char s[10];
int main(){
	cout << "? 10000000000" << endl;
    cin>>s;
    if (s[0]=='Y') {
        long long x=2;
        while(true) {
            cout<<"? "<<x<<endl;
            cin>>s;
            if (s[0]=='Y') {
                cout<<"! "<<x/2<<endl;
                return 0;
            }
            x*=10;
        }
    }
	while(1){
		cout<<"? "<<w<<"\n";
		cin>>s;
		if(s[0]=='N') break;
		w=w*10;
	}
	long long l=w/10,r=w-1,mid;
	while(l!=r){
		mid=(l+r)/2*1000000000;
		cout<<"? "<<mid<<"\n";
		cin>>s;
		if(s[0]=='Y') r=mid/1000000000;
		else l=mid/1000000000+1;
	}
	printf("! %lld\n",l);
	return 0;
}