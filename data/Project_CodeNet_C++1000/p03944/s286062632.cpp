#include <bits/stdc++.h>
#include <string.h>
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

 int main(){

  long long left=0,right,top,bottom=0;
  int n;

  cin>>right>>top>>n;

  for(int i=0;i<n;i++){

    long long x,y,a;
    cin>>x>>y>>a;

    if(a == 1)
        left = max(x,left);
    else if(a == 2)
         right = min(right,x);
    else if(a == 3)
        bottom = max(bottom, y);
    else if(a == 4)
        top = min(y,top);

  }


   int area = (right - left) * (top - bottom);

   if(left >= right || top <= bottom)
    cout<<"0"<<endl;
   else
    cout<<area<<endl;


  return 0;
 }
