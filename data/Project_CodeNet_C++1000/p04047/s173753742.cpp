#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x; cin>>x;
    int a[2*x],s=0; 
    for(int i=0;i<2*x;i++) cin>>a[i];
    sort(a,a+ 2*x);
    for(int i=0;i<2*x;i++){
        s=s+min(a[i],a[i+1]); i++;
    }
    cout<<s<<endl;
}