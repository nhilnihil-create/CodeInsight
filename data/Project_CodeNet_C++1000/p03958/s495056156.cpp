
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

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

 int main(){

 long long k,t;
 cin>>k>>t;

 long long a[t];

 for(int i=0;i<t;i++) cin>>a[i];

   sort(a,a+t);
   long long m=a[t-1];


   if(k %2 == 0){
       if(m<=k/2)
            cout<<"0"<<endl;
       else {
            long long ani = m-k/2;
            cout<<2*ani-1<<endl;
       }
   }
   else {
      if(m <= k/2+1)
      cout<<"0"<<endl;
      else {
            long long ani = m-k/2+1;
            cout<<2*ani<<endl;
      }
   }


 return 0;
 }
