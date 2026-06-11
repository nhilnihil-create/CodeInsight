#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int sum=a+b+c;
    int maxv=max(a,max(b,c));
    cout<<sum-maxv<<endl;
    return 0;
}