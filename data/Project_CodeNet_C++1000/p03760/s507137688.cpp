#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string O, E;
    cin >> O >> E;

    int j=0;
    int k=0;
    for(int i=0; i<O.size()+E.size(); i++){
        if((i+1)%2==0){
            cout << E[j];
            j++;
        }else{
            cout << O[k];
            k++;
        }
    }
    return 0;
}