#include <bits/stdc++.h>
using namespace std;
int main(){
 int64_t a,b;
 cin>>a>>b;
if(a>0){cout<<"Positive"<<endl;}
else if(b<0){if((b-a+1)%2!=0){cout<<"Negative"<<endl;}
        else if((b-a+1)%2==0){cout<<"Positive"<<endl;}
}
else if(a<=0&&b>=0){cout<<"Zero"<<endl;}
}