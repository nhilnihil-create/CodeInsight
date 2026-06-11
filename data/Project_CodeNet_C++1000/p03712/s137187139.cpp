#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int h,w;
    cin>>h>>w;

    vector<vector<char>> p(h+2,vector<char>(w+2,'#'));

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>p[i][j];
        }
    }
    
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            cout<<p[i][j];
        }
        cout<<endl;
    }
}
