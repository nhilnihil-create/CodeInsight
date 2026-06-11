#include <iostream>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int x;
    int i;
    int dist=0;
    for(i=0; i<N; i++){
        cin >> x;
        if(x>K-x) dist+=2*(K-x);
        else dist+=2*x;
    }

    cout << dist << endl;

    return 0;

}