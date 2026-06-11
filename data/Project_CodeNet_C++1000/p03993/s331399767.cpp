#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX_V 100001
#define MOD 1000000007
typedef vector<vector<int> > Graph;

int main(){
   int n;cin>>n;
   int ans=0;
   vector<int> a(n);
   for(int i=0;i<n;i++){
       cin>>a[i];
       a[i]--;
   }
   for(int i=0;i<n;i++){
       if(a[a[i]]==i){
           ans++;
           a[a[i]]=-1;
        }
    }
   cout<<ans<<endl;
}
 

