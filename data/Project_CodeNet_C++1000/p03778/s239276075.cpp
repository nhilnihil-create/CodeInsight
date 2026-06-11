#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,a,b;
    cin>>w>>a>>b;
    if((a<=b&&b<=a+w)||(a<=b+w&&b<=a)) cout<<0<<endl;
    if(a+w<b) cout<<b-(a+w)<<endl;
    if(b+w<a) cout<<a-(b+w)<<endl;
    
}