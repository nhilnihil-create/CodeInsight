#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#define pb push_back
#define ms(a) memset(a,0,sizeof(a))
#define ll long long
#define ull unsigned ll
using namespace std;
#define MAXN 60
#define MAXVAL (1e16+1000)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

ll n , k;

int main(){
	fastio;

    cin >> k;
    n = 50;
    cout << n << endl;
	ll a;
    for( int i = 0 ; i < n ; i++ ){
        a = n - 1 + k / n;
        if(i < k % n){
            a += n - k % n + 1;
        }else{
            a -= k % n;
        }
        cout << a << " ";
    }
	cout << endl;

    return 0;

}
