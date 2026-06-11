#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[i]=(s[i]=='x');
    }

    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            vector<int> res(n);
            res[0]=i,res[1]=j;
            for(int k=2;k<n;k++){
                res[k]=res[k-1]^res[k-2]^ans[k-1];
            }
            bool bn=((ans[n-1]^res[n-2]^res[0]^res[n-1])==0);
            bool b0=((ans[0]^res[n-1]^res[1]^res[0])==0);
            if(bn && b0){
                for(int i=0;i<n;i++){
                    cout<<(res[i] ? "W" : "S");
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;

    return 0;
}