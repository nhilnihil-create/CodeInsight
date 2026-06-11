#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n=s.size();
    long int ans=0;

    //bit
    //i...+を差し込む位置 n-1個
    for(int i=0;i<(1<<n-1);i++){
        long int tmp=0;
        int l=0;
        int r=l+1;
        //j...
        for(int j=0;j<n;j++){
            //最下位bitが1or0
            if((i>>j) & 1){
                tmp+=stol(s.substr(l,r-l));
                l=r;
                r=l+1;
            }else if(j==n-1){
                tmp+=stol(s.substr(l,r));
            }else{
                r++;
            }
        }
        //cout << tmp << endl;
        ans+=tmp;
    }
    cout << ans << endl;

    return 0;
}
