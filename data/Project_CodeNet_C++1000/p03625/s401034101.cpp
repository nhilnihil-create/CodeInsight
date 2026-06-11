#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    ll x=1,b[n],c[n],j=0,k=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1])
            x++;
        else{
            b[j++]=a[i];
            c[k++]=x;
            x=1;
        }
    }
    b[j]=a[n-1];
    c[k]=x;
    for(int i=0;i<k;i++){
        if(c[i]>=4){
            cout<<b[i]*b[i]<<endl;
            return 0;
        }
        else if(c[i]>=2){
            for(int p=i+1;p<=k;p++){
                if(c[p]>=2){
                    cout<<b[i]*b[p]<<endl;
                    return 0;
                }
            }
            break;
        }
    }
    cout<<"0"<<endl;
}
