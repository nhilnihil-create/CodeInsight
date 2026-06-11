#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
  string a;
  cin>>a;
   int l=a.length(),cnt=0;
  for(int i=0;i<l;i++){
    if(a[i]=='A'){
        break;
    }
    else{cnt++;}
  }
  for(int i=l-1;i>=0;i--){
    if(a[i]=='Z'){break;}
    else{cnt++;}
  }
  cout<<l-cnt<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

        solve();

    return 0;
}

