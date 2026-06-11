#include<bits/stdc++.h>
using namespace std;

int x=200000,y=0,i;
string a;


int main(){
    cin>>a;
    for(i=0;i<=a.length()-1;i++){
        if(a[i]=='A'&&i<=x){
            x=i;
        }
    }
    for(i=0;i<=a.length()-1;i++){
        if(a[i]=='Z'&&i>=y){
            y=i;
        }
    }
    cout<<y-x+1;
}