#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

typedef long long ll;


int main(){
    string str;
    cin>>str;
    int count=0;

    for(int i=1;i!=str.size();++i){
        if(str[i]!=str[i-1]){
            ++count;
        }
    }
    cout<<count<<endl;
    
}