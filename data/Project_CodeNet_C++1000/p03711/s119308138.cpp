#include<bits/stdc++.h>
using namespace std;
main(){
long long i,j,k,l,m,n,p;
while(cin>>p>>n){
if((p==4||p==6||p==9||p==1)&&(n==4||n==6||n==9||n==11)) cout<<"Yes"<<endl;
else if((p==1||p==3||p==5||p==7||p==8||p==10||p==12)&&(n==1||n==3||n==7||n==8||n==5||n==10||n==12))cout<<"Yes"<<endl;
else cout<<"No"<<endl;
} return 0;
}