#include <bits/stdc++.h>
using namespace std;
int n,a[100000],MIN,MAX;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            MIN=min(MIN,a[i]);
            MAX=max(MAX,a[i]);
        }
        else MIN=MAX=a[i];
    }
    if(MAX-MIN>1)cout<<"No\n";
    else if(MAX==MIN)cout<<(MAX==n-1||2*MAX<=n?"Yes\n":"No\n");
    else{
        int num=0;
        for(int i=0;i<n;i++)if(a[i]==MAX)num++;
        cout<<(n-num+num/2>=MAX&&n-num<=MIN?"Yes\n":"No\n");
    }
}