#include <iostream>
using namespace std;

int zettaiti(int x){
    if(x>0){
        return x;
    }else{
        return -x;
    }
}

int main(){
    int n,k,key;
    int x;
    int distance = 0;
    cin >> n >> k;
    key = k/2;
    for(int i = 0;i<n;i++){
        cin >> x;
        if(x<=key){
            distance += zettaiti(2*x);
        }else{
            distance += zettaiti(2*(x-k));
        }
    }
    cout << distance << endl;
    return 0;
}