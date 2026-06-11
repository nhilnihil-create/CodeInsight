#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n,num[100005],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        if(num[i]==i) ans++;
    }
    if(!ans){
        cout<<0<<endl;
        return 0;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        if(num[i]==i){
            ans++;
            swap(num[i],num[i+1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}