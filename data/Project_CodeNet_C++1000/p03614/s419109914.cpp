#include <iostream>
#include <cstring>
using namespace std;
int pd[100010],arr[100010];
int main()
{
    int n,ans=0,T=0;
    cin>>n;
    arr[0]=10;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==i) {
            if(T==0&&arr[i-1]==i-1)
            {
                T=1;
            }
            else {ans++;T=0;}
        }
        
    }
    cout<<ans<<endl;
    
}