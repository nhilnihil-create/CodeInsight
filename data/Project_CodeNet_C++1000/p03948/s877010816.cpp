#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n],sub[n];
    //memset(arr,0,n);
    memset(sub,0,n);
    int t;
    cin>>t;
    int mn = 1000000007;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        mn = min(tmp,mn);
        sub[i] = abs(tmp-mn);
    }
    sort(sub,sub+n);
    reverse(sub,sub+n);
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
       if(sub[i]==sub[i+1])
        cnt++;
       else{
        cout<<cnt<<endl;
        return 0;
       }
    }
    cout<<cnt<<endl;

}
