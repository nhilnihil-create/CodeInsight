#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    string S;cin>>S;
    char A=S[0],B=S[1];
    bool flag=true;
    for(int i=2;i<S.size();i++){
        if(S[i]!=A&&S[i]!=B){
            flag=false;
        }
    }
    if(flag) cout<<"Second"<<endl;
    else{
        vector<int> T(26,0);
        for(int i=0;i<S.size();i++){
            T[S[i]-'a']++;
        }
        priority_queue<int> PQ;
        for(int i=0;i<26;i++){
            PQ.push(T[i]);
        }
        int a=PQ.top();
        PQ.pop();
        int b=PQ.top();
        PQ.pop();
        int c=PQ.top();
        PQ.pop();
        int d=PQ.top();
        bool e=true;
        if(S[0]==S[S.size()-1]) e=false;
        if(S.size()==3||!(c==1&&d==0)||a-b>=2){
            if((S.size()%2==1&&e)||(S.size()%2==0&&!e)) cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }else{
            char X;
            for(int i=0;i<26;i++){
                if(T[i]==1) X='a'+i;
            }
            char was=S[0];
            bool check=true;
            bool f=true;
            if(S[0]==X||S[S.size()-1]==X) f=false;
            for(int i=1;i<S.size();i++){
                if(S[i]==X) continue;
                else{
                    if(S[i]==was) check=false;
                    else was=S[i];
                }
            }
            if(!f){
                if(S.size()%2==0) cout<<"Second"<<endl;
                else cout<<"First"<<endl;
            }
            else {
                if(check) cout<<"First"<<endl;
            else cout<<"Second"<<endl;
            }
        }
    }
}
