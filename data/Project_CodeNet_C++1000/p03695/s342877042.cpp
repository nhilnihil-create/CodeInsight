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

int freq[8];

int32_t main()
{ 
    csl;

    int n;
    cin >> n;

    int arr[n];
    int count=0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        if(arr[i]>=3200)
        {
            count++;
        }
    }

    for(int i=0;i<n;i++)
    {
        int curr = arr[i];

        if(curr>=1&&curr<400)
        {
            freq[0]++;   
        }
        else if(curr>=400 && curr<800)
        {
            freq[1]++;
        }
        else if(curr>=800&&curr<1200)
        {
            freq[2]++;
        }
        else if(curr>=1200&&curr<1600)
        {
            freq[3]++;
        }
        else if(curr>=1600&&curr<2000)
        {
            freq[4]++;
        }
        else if(curr>=2000&&curr<2400)
        {
            freq[5]++;
        }
        else if(curr>=2400&&curr<2800)
        {
            freq[6]++;
        }
        else if(curr>=2800&&curr<3200)
        {
            freq[7]++;
        }
    }
    int count0=0;
    for(int i=0;i<8;i++)
    {
        if(freq[i]>0)
        {
            count0++;
        }
    }
    if(count0==0&&count>0)
    {
        cout << 1 << " " << count << "\n";
    }
    else
    {
        cout << count0 << " " << count+count0 << "\n";
    }
}