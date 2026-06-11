#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll a,b;
     cin>>a>>b;
     if(a>0)
        cout<<"Positive"<<endl;
     else if( a<=0 && b>=0)
        cout<<"Zero"<<endl;
     else
     {
         if((abs(b-a)+1)%2==0)
            cout<<"Positive"<<endl;
         else
            cout<<"Negative"<<endl;
     }


}
