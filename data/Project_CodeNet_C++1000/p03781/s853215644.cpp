#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,ans;cin>>x;
    int i=0,p=0;
    while(1){
        p+=i;
        if(x<=p){
            cout<<i<<endl;
            break;
        }
        i++;
    }
}