#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string o,e;
    cin>>o>>e;
    int oe=o.size()+e.size();
    for(int i=0;i<oe;i++){
        if(i%2==0) cout<<o.at(i/2);
        else cout<<e.at(i/2);
    }
}