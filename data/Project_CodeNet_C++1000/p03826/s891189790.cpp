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
    int a,b,c,d;
    cin >> a >> b >> c>> d;
    cout << max(a*b,c*d) << endl;

    return 0;
}

