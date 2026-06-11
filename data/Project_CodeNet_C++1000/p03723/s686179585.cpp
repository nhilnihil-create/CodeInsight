#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;
#define INF 100000000

int main(){
    int A, B, C, counter = 0;
    cin >> A >> B >> C;
    while(A%2 == 0 && B%2 == 0 && C%2 == 0){
        int tmpA = A;
        int tmpB = B;
        int tmpC = C;
        A = tmpB/2 + tmpC/2;
        B = tmpA/2 + tmpC/2;
        C = tmpA/2 + tmpB/2;
        counter++;
        if(counter > INF){
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << counter << endl;
    return 0;
}