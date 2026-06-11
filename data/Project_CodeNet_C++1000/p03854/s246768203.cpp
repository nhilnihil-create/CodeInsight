#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;

int main(){
    string S;
    cin >> S;
    int initial = 0;
    while(initial < S.size()){
        if(initial + 4 >= S.size() || (S[initial] != 'd' && S[initial] != 'e')){
            printf("NO\n");
            return 0;
        }
        if(S[initial] == 'd'){
            if(S[initial+1] != 'r' || S[initial+2] != 'e' || S[initial+3] != 'a' || S[initial+4] != 'm'){
                printf("NO\n");
                return 0;
            }
            if(initial + 5 == S.size()){
                printf("YES\n");
                return 0;
            }
            if(S[initial+5] == 'd'){
                initial += 5;
                continue;
            }
            if(initial + 6 >= S.size() || S[initial+5] != 'e' || S[initial+6] != 'r'){
                printf("NO\n");
                return 0;
            }
            if(initial + 7 == S.size()){
                printf("YES\n");
                return 0;
            }
            if(S[initial+7] == 'a'){
                initial += 5;
                continue;
            }
            initial += 7;
        }else{
            if(S[initial+1] != 'r' || S[initial+2] != 'a' || S[initial+3] != 's' || S[initial+4] != 'e'){
                printf("NO\n");
                return 0;
            }
            if(initial+5 == S.size()){
                printf("YES\n");
                return 0;
            }
            if(S[initial+5] == 'r'){
                initial += 6;
                continue;
            }
            initial += 5;
        }
    }
    printf("YES\n");
	return 0;
}