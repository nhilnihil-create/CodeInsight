//kalyanchirla
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
using namespace std;
#define int long long
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define csl ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007

int freq[100000+1];

int32_t main()
{ 
    csl;

    int n,k;
    cin >> n >> k;

    while(n--)
    {
        int a,b;
        cin >> a >> b;
        freq[a]+=b;
    }
    int sum=0;
    int ans =-1;
    for(int i=1;i<=100000;i++)
    {
        sum+=freq[i];
        if(sum>=k)
        {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}