#include<bits/stdc++.h>
using namespace std;
char a[100001];
string k1="Second\n",k2="First\n";
int main(){
    int f=0;
    while(cin>>a){
        f=strlen(a);
        if(f%2){
            if(a[0]==a[f-1])
                cout<<k1;
            else cout<<k2;
        }
        else {
            if(a[0]==a[f-1])
                cout<<k2;
            else cout<<k1;
        }
    }
    return 0;
}