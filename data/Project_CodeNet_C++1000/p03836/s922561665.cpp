#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

void solve()
{
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int x=tx-sx,y=ty-sy;
    for (int i = 0; i < y; ++i) cout<<"U";
    for (int i = 0; i < x; ++i) cout<<"R";
    for (int i = 0; i < y; ++i) cout<<"D";
    for (int i = 0; i < x; ++i) cout<<"L";
    cout<<"L";
    for (int i = 0; i < y+1; ++i) cout<<"U";
    for (int i = 0; i < x+1; ++i) cout<<"R";
    cout<<"D";
    cout<<"R";
    for (int i = 0; i < y+1; ++i) cout<<"D";
    for (int i = 0; i < x+1; ++i) cout<<"L";
    cout<<"U"<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}