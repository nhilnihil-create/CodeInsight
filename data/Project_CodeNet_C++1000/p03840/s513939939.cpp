#include <iostream>
using namespace std;

int main() {
long long i,o,t,j,l,s,z,c=0,k=0;
cin>>i>>o>>t>>j>>l>>s>>z;
if(i>0&&j>0&&l>0){
if(i%2==1)k++;
if(j%2==1)k++;
if(l%2==1)k++;
if(k==3)c=3;
if(k==2)c=1;
}
c+=(i/2)*2+o+(j/2)*2+(l/2)*2;
cout<<c<<endl;
	return 0;
}