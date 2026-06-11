#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define ll long long int

using namespace std;

ll n,k,x,y;

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> n >> k >> x >> y;
    if(n>=k){
         cout<< k*x+(n-k)*y << endl;
    }
    else{
        cout<< n*x << endl;
    }


    return 0;
}

