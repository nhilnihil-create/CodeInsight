
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define maxii 200005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
 vector<int> vi[maxii];
 vector<int>::iterator child;
typedef vector<lln> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int arr[maxii];
int arr2[maxii];


int main()
{
   cin>>arr[0]>>arr[1]>>arr[2];
   sort(arr,arr+3);
   if(arr[0]+arr[1]==arr[2])
   {
       printf("Yes\n");
   }
   else cout<<"No";

}




