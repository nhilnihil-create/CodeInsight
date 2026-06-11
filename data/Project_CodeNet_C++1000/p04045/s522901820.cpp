//*Here I go out to sea again
//*The sunshine fills my hair
//*And dreams hang in the air

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int a[11],k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
      cin>>a[i];
    }
    int ans=n;
    while(1){
      bool ch=true;
    while(n>0){
      int temp=n%10;
      for(int i=0;i<k;i++){
        if(a[i]==temp){
           ch=false;
          break;
        }
      }
      n=n/10;
    }
    if(ch)
    break;
    ans++;
    n=ans;
  }
    cout<<ans<<"\n";

    return 0;
}
