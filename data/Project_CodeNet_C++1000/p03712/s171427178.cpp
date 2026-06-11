#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e6+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int n,m;
    cin>>n>>m;
    char vec[n+2][m+2];
    for(int i=0;i<=n+1;i++){
        if(i==0||i==n+1){
            for(int j=0;j<=m+1;j++){
                vec[i][j]='#';
            }
        }
        else {
            vec[i][0]=vec[i][m+1]='#';
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                vec[i][j]=c;
            }
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }
}