#include <bits/stdc++.h>

using namespace std;
int main()
{
    string S;
    cin >> S;
    reverse(S.begin(),S.end());
    vector<string> word={"dream", "dreamer", "erase", "eraser"};
    for(int i=0;i<4;i++){
        reverse(word[i].begin(),word[i].end());
    }

    for(int i=0;i<S.size();){
        bool flag=false;
        for(int j=0;j<4;j++){
            if(S.substr(i,word[j].size())==word[j]){
                flag=true;
                i+=word[j].size();
            }
        }
        if(!flag){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}