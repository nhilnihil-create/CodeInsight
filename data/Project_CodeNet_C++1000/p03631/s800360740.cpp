#include <iostream>
using namespace std;
int main(){
    string N; cin >> N;
    int cnt = 0;
    for (int i = 0; i < N.size(); ++i){
        if (N[i] == N[N.size() - i - 1]){
            ++cnt;
        }
    }
    if (cnt == (int)(N.size() + 1 / 2)){
        cout << "Yes" << endl;
    }else{
        cout <<  "No" << endl;
    }
}