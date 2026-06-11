#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

 int s,b,c;

 cin>>s>>b>>c;

 int a[3];
 a[0] = s;
 a[1] = b;
 a[2] = c;

 sort(a,a+3);

 cout<<a[0]+a[1]<<endl;


 return 0;
 }
