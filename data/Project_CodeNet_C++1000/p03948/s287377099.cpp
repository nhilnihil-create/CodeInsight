#include <iostream>
#include <map>
using namespace std;

int main() {
int n,t,a[100000],b[100000],c=0;
map<int,int> m;
cin>>n>>t>>a[0];
b[0]=a[0];

for(int i=1;i<n;i++){
    cin>>a[i];
    b[i]=min(a[i-1],b[i-1]);
    if(a[i]-b[i]>=c){
        c=a[i]-b[i];
        m[c]++;
    }
}

cout<<m[c]<<endl;
	return 0;
}