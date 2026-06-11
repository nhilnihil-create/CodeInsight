#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <climits>
#include <cmath>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <map>
#include <fstream>

#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    long long int n,p,x = 0,t;
    cin>>n>>p;
    for(int i = 0; i < n; i++){
        cin>>t;
        if(t%2 == 1)x++;
    }
    if(p == 1){
        if(x == 0){
            cout<<0<<endl;
        }else{
            cout<<(1LL<<(n-1))<<endl;
        }
    }else{
      if(x == 0){
        cout<<(1LL<<n)<<endl;
      }else{
        cout<<(1LL<<(n-1))<<endl;
      }
    }
}
