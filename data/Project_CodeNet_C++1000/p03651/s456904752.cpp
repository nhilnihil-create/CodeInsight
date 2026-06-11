#include<iostream>
using namespace std;

int balls[100005];

int findFPB(int a, int b){
   if(b == 0) return a;
   return findFPB(b, a%b);
}

int main(){
    int N, K, maks = 0, fpb;

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> balls[i];

        if (balls[i] > maks) maks = balls[i];

        if (i == 1) fpb = balls[i];
        if (i >= 2 && fpb != 1){
            fpb = findFPB(balls[i], fpb);
        }
    }

    if(K > maks){
        cout << "IMPOSSIBLE" << endl;
    } else if(K % fpb == 0){
        cout << "POSSIBLE" << endl;
    } else{
        cout << "IMPOSSIBLE" << endl;
    }
}