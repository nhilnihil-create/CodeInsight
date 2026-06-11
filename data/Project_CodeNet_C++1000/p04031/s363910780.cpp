#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
typedef long long ll;
int main(){
   #ifndef ONLINE_JUDGE 
      FILE_READ_IN 
      FILE_READ_OUT 
   #endif
    int n; cin>>n;
    int a[n];
    ll avg=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        avg+=a[i];
    }
    avg=round(avg/(float)n);
    ll cost=0;
    for(int i=0;i<n;i++)
    {
        cost+=abs(avg-a[i])*abs(avg-a[i]);
    }
    cout<<cost<<"\n";
   return 0;
}