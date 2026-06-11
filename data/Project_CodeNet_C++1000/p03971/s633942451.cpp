#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , a , b; cin>>n>>a>>b;
    string s; cin>>s;
    vector<string>ans(n , "No");
    int cura = 0 , curb = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'a'){
            if(cura < (a + b))ans[i] = "Yes";
            cura++;

        }
        else if(s[i] == 'b'){
            curb++;
            if(cura < (a + b) && curb <= b ){
                ans[i] = "Yes";
                cura++;
            }
        }
    }
    for(string& ss : ans)cout<<ss<<"\n";
}