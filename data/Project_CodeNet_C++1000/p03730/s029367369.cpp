#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;

    int small;
    if(A>B) small=A;
    else small=B;

    int i;
    int GCM=1;
    for(i=1;i<=small; i++){
        if(A%i==0 && B%i==0) GCM=i;
    }

    if(C%GCM==0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}