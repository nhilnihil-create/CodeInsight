#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   int n;
   cin >> n;
   VI a(n), b(n-1);
   rep(i,n)cin >> a.at(i);
   rep(i,n-1){
       b.at(i)=a.at(i+1)-a.at(i);
   }
   int ans=0;
   int w=0;
   rep(i,n-1){
       if(b.at(i)>0 && w==0)w=1;
       else if(b.at(i)<0 && w==0)w=-1;
       else if(b.at(i)==0){
           if(w==0)w==0;
           else if(w==1)w==1;
           else if(w==-1)w=-1;
        }
       else if(b.at(i)>0 && w==-1){
           ans++;
           w=0;
       }
       else if(b.at(i)<0 && w==1){
           ans++;
           w=0;
       }
       else if(b.at(i)>0 && w==1)w==1;
       else if(b.at(i)<0 && w==-1)w==-1;
   }
    cout << ans+1 << endl;
}
       