#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll acum(int m){
    return m*(m+1)/2;
}

int main(){
    int N; cin >> N;
    int m = -1;
    ll sum;
    for(int i=1;i<=N;i++){
        if(acum(i-1) < N && N <= acum(i)){
            m = i;
            sum = acum(i);
            break;
        }
    }
    int k = sum - N;
    for(int i=1;i<=m;i++){
        if(i == k) continue;
        cout << i << endl;
    }
    return 0;
}