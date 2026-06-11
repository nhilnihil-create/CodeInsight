#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;


int main(int argc, char const *argv[]) {
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a%c==0&&b%d==0){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    long long m = 1ll<<25;
    // long long m = 1ll<<2;
    for(int i=0;i<a;++i){
        for(int k=0;k<b;++k){
            if(i%c==0&&k%d==0){
                cout<<m<<" ";
            }
            else if(i%c==c-1&&k%d==d-1){
                cout<<-m-1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}