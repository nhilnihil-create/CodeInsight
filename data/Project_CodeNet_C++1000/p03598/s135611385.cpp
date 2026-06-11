#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
        ll n=0,k=0;
        cin>>n>>k;
        ll array[n]={0};
        for(int i=0;i<n;i++)
            cin>>array[i];
        ll counter=0;
        ll x=0;
        for(int i=0;i<n;i++){
            x=min(array[i],k-array[i]);
           counter+=x;
        }
        cout<<counter*2;


    }

    return 0;
}
