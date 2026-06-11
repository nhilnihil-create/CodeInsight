#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back

void solve(){
   int n;cin>>n;
   map<int,int> mp;
   int a;
   while(cin>>a){
    mp[a]++;
   }
   for(auto i=0;i<n;i++){
      if(n%2==1){
          if(i==0 && mp[i]!=1) { cout<<"0"<<endl; return ;}
          else if(i != 0 && mp[i]!=2 && i%2==0)
          {

            cout<<"0"<<endl; return ;
          }
      }
      else{
        if(mp[i]!=2 && i%2==1) {cout<<"0"<<endl; return; }

      }
   }
   long long r = 1;
  long long m = 1e9 +7;
  for(int i=0; i<n/2; i++){
    r = (r%m * 2)%m;
  }
 
  cout << r << endl;
}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
solve();
  return 0;
}
