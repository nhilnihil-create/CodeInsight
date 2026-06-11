#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int arr[3];
    arr[0]=a+b;
    arr[1]=b+c;
    arr[2]=c+a;
    sort(arr,arr+3);
    cout<<arr[0]<<endl;


    return 0;
}