#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int L,N;
    cin >> N >> L;
    int lengh = N * L;
    vector<string> str_S(N);
    for(int i=0;i<N;i++){
        string S;
        cin >> S ;
        str_S.at(i) = S;
    }
    sort(str_S.begin(), str_S.end());
    for(int i=0;i<N;i++){
        if(i==N-1){
            cout << str_S.at(i) << endl;
        }
        else{
            cout << str_S.at(i) ;
        }
        
    }
}