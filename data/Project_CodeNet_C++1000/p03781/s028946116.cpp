#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define ll long long int
#define ii pair < ll, ll >
#define mp make_pair
#define F first
#define S second

using namespace std;

ll bin(ll t){
    ll lo = 0, hi = t, mid, res = t;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if( t <= mid*(mid+1)/2 ){
            res = mid;
            hi = mid - 1;
        }else lo = mid + 1;
    }
    return res;
}

int main()
{
    ll x;
    cin >> x;
    cout << bin(x);
    return 0;
}















