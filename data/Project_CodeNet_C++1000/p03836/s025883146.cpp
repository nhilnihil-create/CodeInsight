#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int dx=tx-sx;
    int dy=ty-sy;
    cout<<string(dx,'R')<<string(dy,'U');
    cout<<string(dx,'L')<<string(dy,'D');
    cout<<'D'<<string(dx+1,'R')<<string(dy+1,'U')<<'L';
    cout<<'U'<<string(dx+1,'L')<<string(dy+1,'D')<<'R';
    return 0;
}

