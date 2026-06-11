
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
int gcd(int x, int y)
{
    if(y==0)
        return x;
    return gcd(y, x%y);
}

 long long numbers[500005];

//int a[100005];

 int main(){

  long long a,b,c;
  cin>>a>>b>>c;

  if(a== b && b == c && a%2 == 0){
    cout<<"-1"<<endl;
    return 0;
  }

  long long cnt=0;

  while(a%2 == 0 && b%2 == 0&& c%2 == 0 ){
    long long A = a/2,B=b/2,C=c/2;
    a = B+C;
    b = A+C;
    c = A+B;
   cnt++;
  }

  cout<<cnt<<endl;

 return 0;
 }
