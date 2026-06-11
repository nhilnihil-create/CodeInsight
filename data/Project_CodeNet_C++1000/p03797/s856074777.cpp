#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    ll n,m;
    cin>>n>>m;
    if(2*n<m){
        cout<<(n+(m/2))/2<<endl;
    }else{
        cout<<m/2<<endl;
    }    
    return 0;
}