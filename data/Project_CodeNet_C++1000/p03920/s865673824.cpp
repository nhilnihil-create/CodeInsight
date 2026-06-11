#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int sm = 0;
    int mx = 1;
    for(int i=1; i<=N; i++){
        sm += i;
        if(sm >= N){
            mx = i;
            break;
        }
    }
    int rem = sm - N;
    for(int i=1; i<=mx; i++)
        if(i != rem) cout << i << endl;

    return 0;
}