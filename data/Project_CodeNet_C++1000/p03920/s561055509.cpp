#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <thread>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n;
    cin >> n;
    ll s=0;
    ll i=0;
    while(s<n){
        i++;
        s+=i;
    }
    ll hoge = s-n;
    for(int h =1;h<=i;h++){
        if(h!=hoge){
            cout << h << endl;
        }
    }
}
