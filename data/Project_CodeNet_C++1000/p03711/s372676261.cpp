#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, OO = 0x3f3f3f3f, mod = 100000007;

#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
#define sc1(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; //4 Direction
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; //Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int x , y;

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    cin >> x >> y;
    set < int > g1 = {1, 3 , 5, 7 , 8 , 10 , 12};
    set < int > g2 = {4 , 6 , 9 , 11};
    set < int > g3 = {2};
    if(g1.find(x) != g1.end() && g1.find(y) != g1.end())
        cout << "Yes\n";
    else if(g2.find(x) != g2.end() && g2.find(y) != g2.end())
        cout << "Yes\n";
    else if(g3.find(x) != g3.end() && g3.find(y) != g3.end())
        cout << "Yes\n";
    else
        cout << "No\n";


    return 0;
}
