#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
int main(){
    int x;
    cin >> x;
    for(int i=1;i<1e9;i++){
        if((i+1)*i/2>=x){
            cout<<i<<endl;
            return 0;
        }
    }
}