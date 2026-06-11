#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
bool judge(int ans[],string s,int k,int n){
    if(ans[k%n]==1){
        if(s[k%n]=='o' && ans[(k-1)%n]==ans[(k+1)%n]) return true;
        else if(s[k%n]=='x' && ans[(k-1)%n]!=ans[(k+1)%n]) return true;
    }
    else{
        if(s[k%n]=='o' && ans[(k-1)%n]!=ans[(k+1)%n]) return true;
        else if(s[k%n]=='x' && ans[(k-1)%n]==ans[(k+1)%n]) return true;        
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    //1が正直者,-1が嘘つき
    int tmpans[n];
    vector<int> init[4] = {{1,1},{-1,1},{1,-1},{-1,-1}};
    rep(i,4){
        fill_n(tmpans,n,0);
        tmpans[0] = init[i][0];
        tmpans[1] = init[i][1];
        for(int j = 1;j<n-1;j++){
            if(tmpans[j]==1){
                if(s[j]=='o') tmpans[j+1]=tmpans[j-1];
                else tmpans[j+1]=(-1)*tmpans[j-1];
            }
            else{
                if(s[j]=='o') tmpans[j+1]= (-1)*tmpans[j-1];
                else tmpans[j+1]=tmpans[j-1];
            }
        }
        if(judge(tmpans,s,n-1,n)&&judge(tmpans,s,n,n)){
            rep(j,n){
                if(tmpans[j]==1) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}