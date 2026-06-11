#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
//deque/functional/iterator/list/map/memory/numeric/queue/set/stack/utility/vector
//#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;

int main(){
    ios::sync_with_stdio(false);
    int x,y,w;
    cin>>x;
    int i=1;
    int sum=0;
    for(i=1;;i++){
        sum+=i;
        if(sum>=x) break;
    }
    cout<<i<<endl;

    return 0;
}
