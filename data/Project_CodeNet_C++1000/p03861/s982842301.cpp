#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}

int main() {
   fast();
  long long a,b,x;
  cin>>a>>b>>x;
  if(b%x==0 && a%x==0){
    cout<<b/x-a/x+1<<"\n";
  }else if(a%x==0 && b%x!=0){
    cout<<b/x-a/x+1<<"\n";
  }else if(a%x!=0 && b%x==0){
    cout<<b/x-a/x<<"\n";
  }else{
    cout<<b/x-a/x<<"\n";
  }

   
}
