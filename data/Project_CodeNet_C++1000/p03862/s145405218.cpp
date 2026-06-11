

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

int a[100005];

  int main(){

   long long n,x,total=0,sum=0;
   cin>>n>>x;



   for(int i=1;i<=n;i++)
    cin>>a[i];

    for(int i=1;i<=n;i++){
        if(a[i] + a[i-1] > x){
            total = (a[i]+a[i-1] -x);
            sum += total;
            a[i] -= total;
        }
    }

    cout<<sum<<endl;

  return 0;
  }