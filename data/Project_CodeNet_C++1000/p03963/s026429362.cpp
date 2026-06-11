#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))

typedef long long ll;

int main()
{
std:
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    int cnt=1;
    cnt*=k;
    for(int i=n-1;i>0;i--){
        cnt*=k-1;
    }
    cout<<cnt;

    return 0;
}
