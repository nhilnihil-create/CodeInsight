#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

int a[100000];
int p[101][101];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++) {
            if(i&1) {
               p[i][j]=cnt;
            }
            else{
                p[i][w-j+1]=cnt;
            }
            a[cnt]--;
            if(a[cnt]==0) cnt++;
        }
    }

    for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++)
       cout<<p[i][j]<<" ";
       cout<<endl;
    }
    return 0;
}
