#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a[3];
    cin>>a[0]>>a[1]>>a[2];
    int counter=0;
    sort(a,a+3);
    for(int i=0; i<3;i++){
    if(a[i]%2==0){
    counter++;}}
    if(counter>0)
    cout<<0<<endl;
    else
    cout<<a[0]*a[1]<<endl;
}
    
