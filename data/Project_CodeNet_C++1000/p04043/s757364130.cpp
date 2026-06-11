#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a[3];
int main(void){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]==5&&a[1]==5&&a[2]==7){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}
