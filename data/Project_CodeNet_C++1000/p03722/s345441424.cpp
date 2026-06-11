//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) (a).begin(), (a).end()

template<typename T>
void vdeb(vector<T> &da){
    int size=da.size();
    for(int i=0;i<size;i++){
        if(i==size-1){
            cout << da[i] << endl;
        }
        else{
            cout << da[i] << ' ';
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<pair<int,int>, int>> da(m);
    rip(i,m,0){
        cin >> da[i].first.first >> da[i].first.second >> da[i].second;
    }
    vector<ll> ma(n + 1, LLONG_MIN/2);
    ma[1] = 0;
    rip(i,n,0){
        rip(i,m,0){
            ma[da[i].first.second] = max(ma[da[i].first.second], ma[da[i].first.first] + da[i].second);
        }
    }
    ll memo = ma[n];
    rip(i,n,0){
        rip(i,m,0){
            ma[da[i].first.second] = max(ma[da[i].first.second], ma[da[i].first.first] + da[i].second);
        }
    }
    if(memo < ma[n]){
        cout << "inf" << endl;
    }
    else{
        cout << ma[n] << endl;
    }
}