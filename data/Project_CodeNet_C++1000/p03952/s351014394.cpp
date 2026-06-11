/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;

int n ,x ;
deque<int> dq ,all ;
int main(){
    cin >> n >> x ;
    if(x==1 || x==2*n-1) return cout << "No" ,0 ;
    cout << "Yes\n" ;
    dq.push_back(x) ;
    for(int i=1;i<=2*n-1;++i) if(i!=x) all.push_back(i);
    for(int i=0;all.size();i^=1){
        if(!i){
            dq.push_front(all.front());
            dq.push_back(all.back());
        }
        else{
            dq.push_back(all.front());
            dq.push_front(all.back());
        }
        all.pop_front();
        all.pop_back();
    }
    for(int go:dq) cout << go << endl ;
    return 0;
}
