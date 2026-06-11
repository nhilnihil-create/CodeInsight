#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define endll "\n"

#define fin             freopen("input.txt","r",stdin);
#define fout            freopen("output.txt","w",stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,m,n;
    cin >> x >> y >> n >> m;
    for(int i=x;i<n;i++) cout << "R";
    for(int i=y;i<m;i++) cout << "U";
    for(int i=x;i<n;i++) cout << "L";
    for(int i=y;i<m;i++) cout << "D";

    cout << "D";
    for(int i=x;i<=n;i++) cout << "R";
    for(int i=y;i<=m;i++) cout << "U";
    cout << "L" << "U";
    for(int i=x;i<=n;i++) cout << "L";
    for(int i=y;i<=m;i++) cout << "D";
    cout << "R" << endl;
    return 0;
}

