#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<limits>
#include<stack>
#include<array>
#include<stdio.h>
#include<cstring>

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;

int INF = 1000000009; //std::numeric_limits<int>::max();
ll LLINF = 1e15;
int NINF = std::numeric_limits<int>::min();
int MOD = 1e9+7;

int col[] = {1,0,-1,0,1,1,-1,-1};
int row[] = {0,1,0,-1,1,-1,1,-1};

//knight moves
int cc[] = {1,2,2,1,-1,-1,-2,-2};
int rr[] = {-2,-1,1,2,-2,2,1,-1};


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    cout << (a+b)%24 ;
    
    
    return 0;
}
