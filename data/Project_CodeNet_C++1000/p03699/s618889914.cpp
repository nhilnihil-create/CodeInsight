#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n;cin>>n;
    vector<int> arr(n);
    int s=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    sort(arr.begin(),arr.end());

    
    if(s%10==0){
        int i=0;
        while(arr[i]%10==0 && i<n){
            i++;
        }
        if(i==n) s=0;
        else s-=arr[i];
    }

    cout<<s<<endl;
    
}
