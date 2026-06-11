#include <iostream>
using namespace std;

int main() {
long long n,a,b,c,h[100000],l=0,r=1000000001;
cin>>n>>a>>b;
c=a-b;
for(int i=0;i<n;i++){
    cin>>h[i];
}
while(r-l>1){
    long long m=(r+l)/2;
    long long k=0;
    for(int i=0;i<n;i++){
        long long d=h[i]-m*b;
        if(d>0){
            k+=(d+c-1)/c;
        }
        
    }
    if(m>=k){
        r=m;
    }else{
        l=m;
    }
}
cout<<r<<endl;
	return 0;
}