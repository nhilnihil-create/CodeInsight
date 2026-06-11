#include<iostream>
#include<string>
using namespace std;

int main(){
    //input
    string S;
    cin >> S;

    //calc
    long long ans=0;
    long long sub;
    long long i,bit;
    for(bit=0; bit<(1<<(S.length()-1)); bit++){
        sub=S[0]-'0';
        for(i=0; i<(S.length()-1);i++){
            if(bit&(1<<i)){
                ans += sub;
                sub = S[i+1]-'0';
            }else{
                sub = 10*sub + (S[i+1]-'0');
            }
        }
        ans += sub;
    }

    //answer
    cout << ans << endl;
    system("pause");
    return 0;
}