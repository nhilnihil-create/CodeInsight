#include<bits/stdc++.h>
using namespace std;

int main(){

 int n = 3;
 int d,b,c;
 cin>>d>>b>>c;

 int a[n+1];

 a[0] = d;
 a[1] = b;
 a[2] = c;

 sort(a,a+n);

 if(a[2] == a[1]+a[0])
    cout<<"Yes"<<endl;
 else cout<<"No"<<endl;


 return 0;
}
