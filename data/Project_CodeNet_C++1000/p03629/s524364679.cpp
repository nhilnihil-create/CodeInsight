#include <iostream>
using namespace std;
int dp[200001];
int freq[200001][26];
int main(){
    string a;
    cin >> a;
    for(int j=0;j<26;j++) freq[a.length()][j] = 1000000000;
    for(int i=a.length()-1;i>=0;i--){
        for(int j=0;j<26;j++){
            if(a[i]-'a'==j)
                freq[i][j] =i;
            else
                freq[i][j] = freq[i+1][j];
        }
    }
    fill(dp,dp+a.length(),1000000000);
    dp[a.length()] = 1;
    for(int i=a.length()-1;i>=0;i--){
        for(int j=0;j<26;j++){
            if(freq[i][j]==1000000000)
                dp[i] = 1;
            else
                dp[i] = min(dp[i],1+dp[freq[i][j]+1]);
            
        }
    }
    string ret= "";
    int i =0;
    while(i<=a.length()){
        if(i==a.length()){
            ret+="a";
        }
        else{
            int next = 0;
            int nextChar = 27;
            for(int j=0;j<26;j++){
                if(freq[i][j]==1000000000){
                    if(dp[i]==1){
                        if(j<nextChar){
                            nextChar = j;
                            next = 1000000000;
                        }
                    }
                }
                else{
                    if(dp[freq[i][j]+1]+1==dp[i]){
                        if(j<nextChar){
                            nextChar = j;
                            next = freq[i][j]+1;
                        }
                    
                    }
                }
            }
            i = next;
            ret+=(nextChar+'a');

        }
    }
    cout << ret << endl;

}
