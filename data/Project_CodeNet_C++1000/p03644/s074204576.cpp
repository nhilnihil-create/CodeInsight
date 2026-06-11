#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int ans=0;
    int i;

    for(i=1; i<7; i++){
        if(pow(2,i)<=N) ans++;
    }

    cout << pow(2,ans) <<  endl;

    return 0;
}