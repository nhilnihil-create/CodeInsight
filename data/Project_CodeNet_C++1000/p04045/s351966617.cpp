#include <bits/stdc++.h>
using namespace std;

int main()  {
    int n,k,x;
    cin>>n>>k;
    vector<int> a(10,0);
    for(int i=0;i<k;i++){
        cin>>x;
        a[x]=1;
    }
    while(true) {
        int cnt=0,digit,temp=n;
        while(temp>0)   {
            digit=temp%10;
            if(a[digit]!=0) {
                cnt++;
                break;
            }
            temp/=10;
        }
        if(cnt==0)
            break;
        n++;
    }
    cout<<n;
    return 0;
}
