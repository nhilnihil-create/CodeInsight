#include<iostream>

using namespace std;

int cnt[2];

int main(){
    string S;   
    cin >> S;
    for(int i=0; i<=S.length()-1; i++){
        if(S[i] == 'S'){
            cnt[1]++;
        } else{
            if(cnt[1] > 0){
                cnt[1]--;
            } else{
                cnt[2]++;
            }
        }
    }
    cout << cnt[1] + cnt[2] << endl;
}