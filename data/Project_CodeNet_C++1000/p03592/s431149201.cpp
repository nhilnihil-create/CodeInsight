#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    int N, M, K;    cin >> N >> M >> K;
    for(int i=0; i<N+1; i++){
        for(int j=0; j<M+1; j++){
            if(i*j + (N-i)*(M-j) == K){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}