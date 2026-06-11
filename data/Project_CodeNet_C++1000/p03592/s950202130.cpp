#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    int n,m,k;
    cin>>n>>m>>k;


    for(int i=0;i<=n;i++)
    {
        
        for(int j=0;j<=m;j++)
        {
            int b =i*m;
            b-= j*i;
            b+= (n-i)*j;

            if(b==k)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
   
    cout<<"No"<<endl;
}
