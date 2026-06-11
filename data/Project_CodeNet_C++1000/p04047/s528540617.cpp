#include <iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[2*n];
    for(int i=0;i<2*n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+2*n);
    int sum=0;
    for(int i=0;i<2*n-1;i+=2)
    {
        sum=sum+(min(arr[i+1],arr[i]));
    }
    cout<<sum<<endl;



    return 0;
}
