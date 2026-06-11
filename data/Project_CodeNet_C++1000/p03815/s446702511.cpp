#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
using ll = long long;
using ld = long double;
using namespace std;
int main(){
    ll n;
    cin>>n;
    if(n%11==0){
        cout<<n/11*2<<endl;
        return 0;
    }
    if(n%11<=6){
        cout<<(n/11)*2+1<<endl;
    }else{
        cout<<(n/11)*2+2<<endl;
    }

}