#include<iostream>
#include<algorithm>
using namespace std;
long long a[3];

int main(){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);

    if(a[2]%2==0)
        cout<<0;
    else
        cout<<a[0]*a[1];
}