#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int k = 1;
    for(int i = 0;i<10;i++){
        if(k*2>n) break;
        else k *=2;
    }
    cout<<k;
    return 0;
}