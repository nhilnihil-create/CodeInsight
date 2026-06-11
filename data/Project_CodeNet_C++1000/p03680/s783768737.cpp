#include <iostream>

using namespace std;

int main()
{
    int n,a[100001],i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=1,sum=1;
    while(a[x]!=2){
        x=a[x];
        sum+=1;
        if(sum>n) break;
    }
    if(sum<=n) cout<<sum;
    else if (sum>n) cout<<"-1";
    return 0;
}
