#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j,temp,sum;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    int p[m],x[m];
    for(i=0;i<m;i++){
        cin>>p[i]>>x[i];
    }
    for(i=0;i<m;i++){
        temp=a[p[i]-1];
        a[p[i]-1]=x[i];
        sum=0;
        for(j=0;j<n;j++){
            sum+=a[j];
        }
        cout<<sum<<endl;
        a[p[i]-1]=temp;
    }
    return 0;
}
