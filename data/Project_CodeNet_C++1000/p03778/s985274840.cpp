#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int w,a,b;
    cin>>w>>a>>b;
    if(a>b)swap(a,b);
    if(a+w>=b)cout<<0<<endl;
    else cout<<b-(a+w)<<endl;
    return 0;
}