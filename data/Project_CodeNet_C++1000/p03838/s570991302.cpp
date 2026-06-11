#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007
void setIO(string name) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((name+".in").c_str(),"r",stdin);
  freopen((name+".out").c_str(),"w",stdout);
}
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}


int main() {
   fast(); 
   long long x,y;
   cin>>x>>y;
   if(x*y<0){
    cout<<abs(abs(x)-abs(y))+1<<endl;
     return 0;
   }else{
     if(y==0){
        if(x>0){
          cout<<x+1<<"\n";
          return 0;
        }else{
          cout<<abs(x)<<"\n";
          return 0;
        }
     }
     if(x==0){
        if(y>0){
           cout<<y-x<<"\n";
          return 0;
        }else{
           cout<<abs(y)+1<<"\n";
          return 0;
        }
     }
     if(x<=y){
       
       cout<<y-x<<"\n";
       return 0;
     }else{
        cout<<-y+x+2<<"\n";
       return 0;
     }
   }
   

} 
