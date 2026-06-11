#include<bits/stdc++.h>
using namespace std;

int i;
string a;


int main(){
    cin>>a;
    a.erase(5,1);
    a.erase(12,1);
    for(i=0;i<=a.length()-1;i++){
        cout<<a[i];
        if(i==4){
            cout<<" ";
        }
        else if(i==11){
            cout<<" ";
        }
    }
}