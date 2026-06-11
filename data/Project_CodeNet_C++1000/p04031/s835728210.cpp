#include <iostream>

#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
//const char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};



void solver() {
    // Write your code here
    int my=0,n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        my+=arr[i];
    }
    int var,var1;
        var=my/n;
        var1=var+1;

    int ans=0;
    int ans1=0;
    for(int i=0;i<n;i++)
    {
        int m=(var-arr[i])*(var-arr[i]);
        ans+=m;
        int m1=(var1-arr[i])*(var1-arr[i]);
        ans1+=m1;
    }
    cout<<min(ans,ans1);
























}


int main() {
    int n=1;
    //cin>>n;
    while(n--)
    {
        solver();
    }
}
