#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)
int main(){
    ll X,Y;
    cin>>X>>Y;
    int Z=X%3-Y%3+3;
    if(Z%3==0){
        if(X==Y) cout<<"Brown"<<endl;
        else cout<<"Alice"<<endl;
    }else if(Z%3==1){
        if(X==Y+1) cout<<"Brown"<<endl;
        else cout<<"Alice"<<endl;
    }else{
        if(Y==X+1) cout<<"Brown"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}