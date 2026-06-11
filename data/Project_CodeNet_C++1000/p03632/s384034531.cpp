#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int count=0;
    for(int i=A;i<B;i++){
        for(int j=C;j<D;j++){
            if(i==j) count++;
        }
    } 
    cout << count << endl;
}