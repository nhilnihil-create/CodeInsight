#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N,M;
    cin >> N >> M;
    vector<int> A(M);
    vector<int> B(M);
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b ;
        A.at(i) = a;
        B.at(i) = b;
    }
    for(int i=1;i<=N;i++){ // 各都市に関するfor
        int count =0;
        for(int j=0;j<M;j++){
            if( A.at(j) == i){
                count++;
            }
            if( B.at(j) == i){
                count++;
            }
        }
        cout << count << endl;
    }
}