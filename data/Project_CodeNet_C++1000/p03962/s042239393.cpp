#include<bits/stdc++.h>

using namespace std;

int main(){
    set<int>tree;
    for(int i=0,k;i<3;i++){
        cin>>k;
        tree.insert(k);
    }
    cout<<tree.size();
    return 0;
}
