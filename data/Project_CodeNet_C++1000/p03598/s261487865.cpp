#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k,c=0,a;
cin>>n>>k;
for(int i=0;i<n;i++){
cin>>a;
c+=min(a,k-a)*2;
}
cout<<c;
}
