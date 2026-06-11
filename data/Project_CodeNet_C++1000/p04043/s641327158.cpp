#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl '\n'
int main()
{
    optimize();
    int cnt_5=2,cnt_7=1,ar[4],c=0,d=0;
    for(int i=0;i<3;i++){
        cin>>ar[i];
    }
    for(int i=0;i<3;i++)
    {
        if(ar[i]==5)
        {
          c++;
        }
        else if(ar[i]==7)
        {
            d++;
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }
    if(cnt_5==c && cnt_7==d)
    {
        cout<<"YES"<<nl;
    }
    else{
         cout<<"NO"<<nl;
    }

return 0;
}

