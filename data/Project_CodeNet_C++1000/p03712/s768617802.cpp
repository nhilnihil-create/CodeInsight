#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int n, m;
    cin >> n >> m;
    n+=2, m+=2;
    char a[n][m];
    for(int i=1; i<=n-2; ++i)
        for(int j=1; j<=m-2; ++j)
            cin >> a[i][j];
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i==0 || j==0 || j==m-1 || i==n-1)
                cout << "#";
            else
                cout << a[i][j];
        }
        cout << endl;
    }
}
