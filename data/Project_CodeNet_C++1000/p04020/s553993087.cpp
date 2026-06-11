#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <int>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(int i=0;i<n;i++)
#define loopj(n)	for(int j=0;j<n;j++)
#define endl	"\n"
ll mod=1e9+7;
const int N = 1e6+7;
int arr[N];
int main()
{
      //freopen ("output.txt","w",stdout);
        ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);

        int n;
        cin >>n;
        loop(n)cin >> arr[i];
        ll tot=0,tmp=0;
        loop(n+1){
            if(arr[i]==0){
                tot+=tmp/2;
                tmp=0;
            }
            tmp+=arr[i];
        }
        cout << tot <<endl;
}
