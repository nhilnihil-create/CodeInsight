/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.'p

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int main(){

 int a[3];

 for(int i=0;i<3;i++)
    cin>>a[i];

 sort(a,a+3,greater<int>());

 if(a[0] == a[1]+a[2])
    cout<<"Yes"<<endl;
 else
    cout<<"No"<<endl;

 return 0;
 }
