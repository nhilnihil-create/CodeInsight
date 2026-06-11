#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    int n; cin >> n;
    int four = 0,two = 0;
    rep(i,n){
        ll a; cin >> a;
        if(a % 4 == 0) four++;
        if(a % 2 == 0) two++;
    }
  	two -= four;

    if(four >= n / 2){
        cout << "Yes" << endl;
        return 0;
    }else if(two == n){
        cout << "Yes" << endl;
        return 0;
    }else if(two + four >= n / 2 + 1 && (n - 2 * four) == two){
      cout << "Yes" << endl;
      return 0;
    }

    cout << "No" << endl;
}