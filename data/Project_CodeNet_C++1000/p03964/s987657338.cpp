#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    vector<int> T(N), A(N);
    for (int i=0; i<N; i++){
        cin >> T.at(i) >> A.at(i);
    }
    long long base, t, a;
    for (int i=0; i<N; i++){
        if (i==0){
            base=1;
        } else {
            base=max((T.at(i-1)*base+T.at(i)-1)/T.at(i), (A.at(i-1)*base+A.at(i)-1)/A.at(i));//整数A/Bの切り上げは以下のように行う。”(A+B-1)/B”
        }
        t=T.at(i)*base;
        a=A.at(i)*base;
    }
    cout << t+a << endl;
    return 0;
}