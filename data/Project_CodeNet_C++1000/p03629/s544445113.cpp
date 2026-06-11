#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int INF = 1000000000;

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

int main(){
    //input
    string S;
    cin >> S;

    //calc
    vector<vector<int> > next = calcNext(S);
    int n=S.length();
    vector<int> dp(n+1,INF);
    dp[n]=1;
    int i,j;
    for(i=n-1; i>=0; i--){
        for(j=0; j<26; j++){
            if(next[i][j]>=n){
                dp[i]=1;
            }else{
                dp[i]=min(dp[i],dp[next[i][j]+1]+1);
            }
        }
    }

    //output
    int now=0;
    while(dp[now]>1){
        for(i=0; i<26; i++){
            if(dp[now]==dp[next[now][i]+1]+1){
                cout << (char)('a'+i);
                now = next[now][i]+1;
                break;
            }
        }
    }
    for(i=0; i<26; i++){
        if(next[now][i]>=n){
            cout << (char)('a'+i) << endl;
            break;
        }
    }
    
    system("pause");
    return 0;
}