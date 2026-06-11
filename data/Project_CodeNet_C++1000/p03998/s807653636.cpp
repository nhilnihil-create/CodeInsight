

#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

 int gcd(int a,int b){

   if(a%b == 0)
    return b;
   else
    return gcd(b,a%b);
 }

 long long numbers[500005];

 int main(){

  string a,b,c;
  cin>>a>>b>>c;

  char n = a[0];
  a.erase(0,1);

  while(1){

     if(n == 'a'){
        if(a.size() == 0){
            cout<<"A"<<endl;
            return 0; }
          n = a[0];
          a.erase(0,1);
     }else if(n == 'b'){
        if(b.size() == 0){
            cout<<"B"<<endl;
            return 0;
        }
        n = b[0];
        b.erase(0,1);
     }
     else if(n == 'c'){
         if(c.size() == 0){
            cout<<"C"<<endl;
            return 0;
         }
         n = c[0];
         c.erase(0,1);
       }
  }


 return 0;
 }