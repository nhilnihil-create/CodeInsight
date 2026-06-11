#include <iostream>
#include <vector>
using namespace std;

int main(){
    string S;
    cin >> S;
    int res = (int)S.size();//INF
    for(char c:S){
        int tmp = 0;
        for(int i = 0; i < S.size();){
            int j = i;
            while(j < S.size() && !((S[j] == c)^(S[i] == c)))++j;
            if(S[i]!=c)tmp = max(tmp,j-i);
            i = j;
        }
        res = min(res,tmp);
    }
    cout << res << endl;
}