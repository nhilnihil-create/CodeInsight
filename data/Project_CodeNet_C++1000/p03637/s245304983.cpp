#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n;
    cin>>n;
    int a[n];
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%4==0)x++;
        else if(a[i]%2==0)y++;
        else z++;
    }
    if(y==0){
        if(x+1>=z)cout<<"Yes";
        else cout<<"No";
    }else{
        if(x>=z)cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}