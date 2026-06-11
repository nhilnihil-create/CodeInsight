#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;


int main(int argc, char const *argv[]) {
    long long n;cin>>n;
    n++;
    deque<int> dq;
    int k = 0;
    while(n>>k > 0)k++;
    k-=2;
    int l = 1;
    for(;k>-1;k--){
        dq.push_back(l);
        l++;
        if((n>>k)%2==1){
            dq.push_front(l);
            l++;
        }
    }
    cout<<2*(l-1)<<endl;
    for(int i=1;i<l;++i)cout<<i<<" ";
    for(int i:dq)cout<<i<<" ";
    cout<<endl;
    return 0;
}