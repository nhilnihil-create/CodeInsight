#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,c;
    for(;;){
        cin>>n;
        cin>>a;
        c=n*n;
        if(0<=n&&n<=100&&0<=a&&a<=c){
            b=c-a;
            cout<<b<<endl;
            break;
        }
    }
}