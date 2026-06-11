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

int n ;
pair < int , int > arr[N];

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        cin >> arr[i].first >> arr[i].second; // idx , val

    sort(arr , arr + n);
    pair < ll , ll > mn = arr[n-1];
    ll idx = mn.first ;
    ll val = mn.second;
    ll cnt = idx;
    if(val != 0)
        cnt += val;
    cout << cnt << "\n";

    return 0;
}
