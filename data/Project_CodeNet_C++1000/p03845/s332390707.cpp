#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin >>vec.at(i);
    }
    int M;
    cin >>M;
    for(int i=0;i<M;i++){
        int count=0;
        int P,X,C;
        cin >>P>>X;
        C=vec.at(P-1);
        vec.at(P-1)=X;
        for(int j=0;j<N;j++){
            count+=vec.at(j);
        }
        cout << count <<endl;
        vec.at(P-1)=C;
    }

}