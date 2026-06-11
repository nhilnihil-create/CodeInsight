#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {cin.tie(0);
   	ios::sync_with_stdio(false);
    long long k;
    cin >>k;
    long long a[50];
    long long q,r;
    r=k%50;
    q=(k-r)/50;
    for(int i=0;i<50;++i){
        a[i]=50+q-1;
    }
    for(int i=0;i<r;++i){
        a[i]+=50-r+1;
    }
    for(int i=r;i<50;++i){
        a[i]=a[i]-r;
    }
    cout<<50<<endl;
    for(int i=0;i<50;++i){
        cout<<a[i];
        if(i!=49){cout <<" ";}else{cout <<endl;}
    }
    return 0;
}
