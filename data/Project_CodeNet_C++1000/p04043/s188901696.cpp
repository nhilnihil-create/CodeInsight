/*Always success does not build on success,success build on failure and hardwork*/
#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define vec         vector<int>
#define map         map<int,int>
#define scn(t)      scanf("%d",&t);
#define lscn(t)      scanf("%lld",&t);
#define mod         1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define endl        "\n"
using namespace std;
const int N=1e5+5;
int main()
{
      int arr[3];

      scn(arr[0]);
      scn(arr[1]);
      scn(arr[2]);

      sort(arr,arr+3);

      if(arr[0]==5 && arr[1]==5 && arr[2]==7)
      {
          cout<<"YES";
      }
      else
      {
          cout<<"NO";
      }
}

