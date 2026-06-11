#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(x) (x).rbegin(), (x).rend()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,lgm=0;
    cin>>n;
    int arr[n];
    int  colour[9]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<=399){
            colour[0]=1;
        }else if(arr[i]>=400&&arr[i]<=799)
        {
            colour[1]=1;
        }else if(arr[i]>=800&&arr[i]<=1199)
        {
            colour[2]=1;
        }else if(arr[i]>=1200&&arr[i]<=1599)
        {
            colour[3]=1;
        }else if(arr[i]>=1600&&arr[i]<=1999)
        {
            colour[4]=1;
        }else if(arr[i]>=2000&&arr[i]<=2399)
        {
            colour[5]=1;
        }else if(arr[i]>=2400&&arr[i]<=2799)
        {
            colour[6]=1;
        }else if(arr[i]>=2800&&arr[i]<=3199)
        {
            colour[7]=1;
        }else{
        lgm++;
        }
    }
    int ans=0,m;
        for(int i=0;i<=7;i++)
        ans=ans+colour[i];
        if(ans==0)m=1;
        else m=ans;
    cout<<m<<" "<<ans+lgm<<endl;


}
