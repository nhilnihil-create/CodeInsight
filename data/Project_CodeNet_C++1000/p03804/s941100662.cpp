#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const int SIZE = 51;
char a[SIZE][SIZE];
char b[SIZE][SIZE];
int n, m; 

bool isContained(){

    for (int i=0;i<=n-m; i++)
        for (int j=0; j<=n-m; j++){
            int isEqual = true;  
            for (int x=0; x<m; x++)
                for (int y=0; y<m; y++)
                    if(a[i+x][j+y]!=b[x][y])
                        isEqual = false;
            if(isEqual) return true;
        }
     return false;
}

void solve(){
   cin>>n>>m;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin>>a[i][j];

    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++) cin>>b[i][j];

    cout<<(isContained()?"Yes":"No")<<endl;
}

int main(){
    solve();
    Bye;
}