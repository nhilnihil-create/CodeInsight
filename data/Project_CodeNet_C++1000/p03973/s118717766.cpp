///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >

const int maxn = 1000* 100 + 5;
int a[maxn];

int32_t main(){
    int mn = 2, n, ans = 0;
    cin >>n;
    for(int i = 0; i < n; i ++)
        cin >>a[i];
    ans = a[0] - 1;
    for(int i = 1; i < n; i ++){
        if(a[i] == mn)
            mn ++;
        else if(a[i] > mn){
            ans += (a[i] - 1)/ mn;
        }
    }
    cout <<ans <<endl;
    return false;
}
