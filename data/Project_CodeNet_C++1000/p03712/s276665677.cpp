#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long h,w;
    cin>>h>>w;
    string a[h];
    f(i,0,h){
        cin>>a[i];
    }
    f(i,0,w+2){
        cout<<"#";
    }
    cout<<endl;
    f(i,0,h){
        cout<<"#"<<a[i]<<"#"<<endl;
    }
    f(i,0,w+2){
        cout<<"#";
    }
    cout<<endl;
    return 0;
}
