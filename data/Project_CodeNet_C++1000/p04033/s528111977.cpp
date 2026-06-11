#include <bits/stdc++.h>
using namespace std;
long long a,b,s;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>a>>b;
s=a+b;
if(a>0&&b>0)cout<<"Positive";


else if(a<0&&b<0&&s%2==0)cout<<"Negative";
else if(a<0&&b<0&&s%2!=0)cout<<"Positive";

else if(s==0)cout<<"Zero";
}

