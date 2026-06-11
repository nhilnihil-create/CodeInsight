#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    string s; cin >> s;
    int ans=INF;
    for(int i=0;i<26;i++){
        char tmp='a'+i;
        int N=s.size();
        bool flag=false;
        for(int i=0;i<N;i++){
            if(s[i]==tmp){
                flag=true;
                break;
            }
        }
        if(!flag) continue;
        string c=s;
        int cnt=0;
        while(true){
            flag=true;
            string cur="";
            for(int i=0;i<N-1;i++){
                if((c[i]==tmp)||(c[i+1]==tmp)){
                    cur+=tmp;
                }else{
                    cur+=c[i];
                }
            }
            for(int i=0;i<N-1;i++){
                if(cur[i]!=tmp){
                    flag=false;
                    break;
                }
            }
            if(flag||N==0) break;
            cnt++;
            c=cur;
            N--;
        }
        ans=min(ans,cnt);
    }
    if(ans==0){
        cout << 0 << endl;
    }else{
        cout << ans+1 << endl;
    }
    
}