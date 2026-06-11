#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
using namespace std;
using P=pair<int,int>;
using PP=pair<P,P>;
using ll=long long;
int main(){
    int x,y,ret=INT_MAX;
    cin>>x>>y;
    if(x<=y){
        ret=min(ret,y-x);
    }
    if(-x<=y){
        ret=min(ret,1+y+x);
    }
    if(x<=-y){
        ret=min(ret,1+-y-x);
    }
    if(-x<=-y){
        ret=min(ret,2+-y+x);
    }
    cout<<ret<<endl;
}