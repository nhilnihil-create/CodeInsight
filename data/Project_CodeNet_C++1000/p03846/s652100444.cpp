#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    int arr[n];
    int x[n]={0};
    for (int i=0;i<n;i++){
        cin>>arr[i];
        x[arr[i]]++;
    }if (n%2==1){
        if (x[0]!=1){
            cout<<0<<endl;
            return 0;
        }
        for (int i=2;i<n;i+=2){
            if (x[i]!=2){
                cout<<0<<endl;
                return 0;
            }
        }int p=1;
        for (int i=2;i<n;i+=2){
            p=(p*x[i])%1000000007;
        }cout<<p%1000000007;
    }else{
        for (int i=1;i<n;i+=2){
            if (x[i]!=2){
                cout<<0<<endl;
                return 0;
            }
        }int p=1;
        for (int i=1;i<n;i+=2){
            p=(p*x[i])%1000000007;
        }cout<<p%1000000007;
    }

    return 0;
}