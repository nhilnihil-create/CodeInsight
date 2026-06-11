#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int N, L;
    vector<string> S;
    string tmp;
    cin >> N >> L;
    for(int i=0; i<N; i++){
        cin >> tmp;
        S.push_back(tmp);
    }
    string tmp2;
    for(int i=0; i<S.size(); i++){
        for(int j=i+1; j<S.size(); j++){
            if(S[i] > S[j]){
                tmp2 = S[i];
                S[i] = S[j];
                S[j] = tmp2;
            }
        }
    }
    for(int i=0; i<S.size(); i++){
        cout << S[i];
    }
    cout << endl;
    return 0;
}