#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    int sx, sy, tx, ty;

    cin >> sx >> sy >> tx >> ty;

    string prix, priy, nprix, npriy;

    if(sx > tx)
    {
        prix = "L";
        nprix = "R";
    }
    else
    {
        prix = "R";
        nprix = "L";
    }

    if(sy > ty)
    {
        priy = "D";
        npriy = "U";
    }
    else
    {
        priy = "U";
        npriy = "D";
    }

    for(int i = 0; i < abs(ty - sy); i++)
    {
        cout << priy;
    }
    for(int i = 0; i < abs(tx - sx); i++)
    {
        cout << prix;
    }
    for(int i = 0; i < abs(ty-sy); i++)
    {
        cout << npriy;
    }
    for(int i = 0; i < abs(tx - sx); i++)
    {
        cout << nprix;
    }

    cout << nprix;
    for(int i = 0; i < abs(ty-sy) + 1; i++)
    {
        cout << priy;
    }
    for(int i = 0; i < abs(tx - sx) + 1; i++)
    {
        cout << prix;
    }
    cout << npriy;
    cout << prix;
    for(int i = 0; i < abs(ty-sy) + 1; i++)
    {
        cout << npriy;
    }
    for(int i = 0; i < abs(tx-sx) + 1; i++)
    {
        cout << nprix;
    }

    cout << priy << endl;

}