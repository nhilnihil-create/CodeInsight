#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int D()
{
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
const int N=2e5+9;

int arr[N];
   ll mod=1e9+7,sum=1;
   bool r= 0;
int main(){
   int  n =D();
   for(int i=0;i<n;i++)
   {

    int a=D();
    arr[a]++;
   }
         for(int i=!(n&1);i<n;i+=2){
            if(i)
                {
         if(arr[i]!= 2) r = 1;
            sum *=2;
            sum = sum % mod;
                }
                else if(arr[i] != 1) r = 1;
         }
  (r)?puts("0"):printf("%lld",sum);
    }

/**


8
7 5 1 1 7 3 5 3
bool ok(int val){
  int cntm=0,cntp=0;
  for(int i=0;i<n-val;i++)
  {
      cntm=0;cntp=0;
      for(int j=i;j<val;j++)
      {
      (arr[j]==1)?cntp++:cntm++;
      }
      if(cntp==cntm)
        break;
  }
  return cntp==cntm;
}
int binarySearch(){
  int low = 0, med, hi =n;
  while(low<hi){
    med = (low+hi+1)>>1;
    cout<<med<<" "<<hi<<" "<<low<<endl;
    if(ok(med))  low = med;
    else  hi = med-1;
  }
  return low;
}*/



/**
  int power1(int b, int p){               //O(p)
    if(!p)  return 1;
    return b*power1(b, p-1);
  }
  int power2(int b, int p){               //O(Log(p))
    if(!p)  return 1;
    int ret = power2(b, p/2);
    return (p&1 ? ret*ret*b : ret*ret);
  }
   int mul(int a, int b, int m){
      return (a%m * b%m) % m;
  }

*/


/**
void seive()
{
    bitset<N>iscomp;
    iscomp[0]=iscomp[1]=1;
    for(long long i=2; i<=N; ++i)
    {
        if(!iscomp[i])
        {
            a.push_back(i);
            for(long long j=i*i; j<=N; j+=i)
                iscomp[j]=1;
        }
    }
}
3
abc
abc
*/

    /**


    */
