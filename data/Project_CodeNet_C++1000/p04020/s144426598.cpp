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
    int n;
    cin>>n;
    ll ret=0,now=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==0){
            ret+=now/2;
            now=0;
        }else{
            now+=a;
        }
    }
    ret+=now/2;
    cout<<ret<<endl;
}