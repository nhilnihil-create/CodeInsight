#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N , M , X , Y;
    cin >> N >> M;
    vector V(N , 1) , B(N , 0);
    B.at(0) = 1;
    while(cin >> X >> Y){
        V.at(--X)--, V.at(--Y)++;
        if(B.at(X)){
            B.at(Y) = 1;
        }
        if(!V.at(X)){
            B.at(X) = 0;
        }
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        count += V.at(i) && B.at(i);
    }
    cout << count << "\n";
}