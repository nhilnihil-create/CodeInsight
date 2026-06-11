#include <bits/stdc++.h>
using namespace std;
int main(void){

int a,b,c;
cin>>a>>b>>c;

if((c>a&&b>c)||(c==a&&b>c)||(c>a&&b==c)||(c==a&&c==b)){
    cout<<"Yes"<<endl;
    }

else{
    cout<<"No"<<endl;
}
}