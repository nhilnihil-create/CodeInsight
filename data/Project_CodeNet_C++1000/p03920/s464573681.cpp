#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <iterator>
#include <sstream>
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
#define modmod 1000000007
#define modddd 998244353

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,k,n) for(int i=k;i<n;i++)

int main(){
    int N;
    cin >> N;

    ll count = 0;
    ll num;

    for(int i = 1; i <= N; i++){
        count += i;
        if(count >= N){
            num = i;
            break;
        }
    }
    //printf("num : %d\n",num);

    vector<ll> result;
    ll count2 = 0;

    for(int i = num; i >= 1; i--){
        result.push_back(i);
        count2 += i;
        //printf("count2 : %d\n",count2);
        if(count2 > N){
            result.pop_back();
            count2 -= i;
        }
        if(count2 == N){
            break;
        }
    }

    for(int x : result){
        cout << x << endl;
    }

    return 0;

}
