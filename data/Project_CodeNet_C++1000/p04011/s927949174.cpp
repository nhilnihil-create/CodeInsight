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
    int k; cin>>k;
    int x; cin>>x;
    int y; cin>>y;

    if(k>=n)
    {
        cout<<x*n<<"\n";
    }
    else{
        cout<<(x*k+(n-k)*y)<<"\n";
    }
   return 0;
}