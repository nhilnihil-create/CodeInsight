#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int n = sizeof(a)/sizeof(a[0]); 
    sort(a, a+n); 
    //a.sort();
    if(a[0]+a[1]==a[2]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}