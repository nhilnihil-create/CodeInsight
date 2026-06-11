#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;

    int sSize = S.size();
    int end = S.size() - 3;

    int len = end + 1;

    while(end > 0){
        len = end + 1;
        bool match = true;
        
        for(int i = 0 ; i < len/2; i++){
            if(S[i] != S[len/2 + i]){
                match = false;
                break;
            }
        }

        if(match) break;

        end -= 2;
    }

    cout << len << endl;
    return 0;
}
