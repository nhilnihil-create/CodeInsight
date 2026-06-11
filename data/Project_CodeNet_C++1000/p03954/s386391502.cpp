#include <iostream>
#include<bits/stdc++.h>
#define ref(i,n) for(int i=1;i<=n;i++)
using namespace std;

int a[200002],b[200002];
int main()
{
    int n;
    cin>>n;
    ref(i,2*n-1) {
        cin>>a[i];
        b[a[i]]=i;
    }
    int low,high,r;

    if(a[n]>a[n+1]) {
        high=a[n];
        low=a[n+1];
        r=1;
        }
    else {
        r=-1;
        high=a[n+1];
        low=a[n];
    }
    ref(i,n-1){
        int x=pow(-1,i%2)*r,ju=0;
        if((a[n+i]-a[n+i-1])*x>0){
            if((x==1&&a[n+i]>low))
                high=min(high,a[n+i]);
            else if((x==-1&&a[n+i]<high))
                low=max(low,a[n+i]);

            else {
                if(x==-1) {
                    cout<<high;
                    return 0;
                }
                else {
                    cout<<low;
                    return 0;
                }
            }
        }
        else if(x==-1) {
                    cout<<high;
                    return 0;
                }
                else {
                    cout<<low;
                    return 0;
                }
        if((a[n-i]-a[n-i+1])*x>0){
            if((x==1&&a[n-i]>low))
                high=min(high,a[n-i]);
            else if((x==-1&&a[n-i]<high))
                low=max(low,a[n-i]);
            else {
                if(x==-1) {
                    cout<<high;
                    return 0;
                }
                else {
                    cout<<low;
                    return 0;
                }
            }
        }
        else if(x==-1) {
                    cout<<high;
                    return 0;
                }
                else {
                    cout<<low;
                    return 0;
                }

    }

    if(b[low]%2) cout<<low;
    else cout<<high;
    return 0;
}
