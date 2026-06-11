#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    ll N;
    cin>>N;
    string s;
    cin >> s;


    while(1){
    vector<string> ani1(N,"?");
    ani1[0]="s";
    if(s[0]=='o'){
        ani1[N-1]="s";
        ani1[1]="s";
    }
    else {ani1[N-1]="s";
          ani1[1]="w";}
    for(ll i=2;i<=N-2;i++){
        if(ani1[i-1]=="s"){
            if(s[i-1]=='o'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='x'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
        else if(ani1[i-1]=="w"){
            if(s[i-1]=='x'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='o'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
    ;}
    bool c=1,d=1;
    if(ani1[N-2]=="s"&&s[N-2]=='o'&&ani1[N-3]==ani1[N-1])c=0;
    else if(ani1[N-2]=="s"&&s[N-2]=='x'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='o'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='x'&&ani1[N-3]==ani1[N-1])c=0;
    if(ani1[N-1]=="s"&&s[N-1]=='o'&&ani1[N-2]==ani1[0])d=0;
    else if(ani1[N-1]=="s"&&s[N-1]=='x'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='o'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='x'&&ani1[N-2]==ani1[0])d=0;
    if(c==0&&d==0){
        for(ll i=0;i<N;i++){
            if(ani1[i]=="s")cout<<"S";
            else cout<<"W";
        ;}cout<<endl;return 0;
    }break;}
    
    while(1){
    vector<string> ani1(N,"?");
    ani1[0]="s";
    if(s[0]=='o'){
        ani1[N-1]="w";
        ani1[1]="w";
    }
    else {ani1[N-1]="w";
          ani1[1]="s";}
    for(ll i=2;i<=N-2;i++){
        if(ani1[i-1]=="s"){
            if(s[i-1]=='o'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='x'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
        else if(ani1[i-1]=="w"){
            if(s[i-1]=='x'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='o'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
    ;}
    bool c=1,d=1;
    if(ani1[N-2]=="s"&&s[N-2]=='o'&&ani1[N-3]==ani1[N-1])c=0;
    else if(ani1[N-2]=="s"&&s[N-2]=='x'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='o'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='x'&&ani1[N-3]==ani1[N-1])c=0;
    if(ani1[N-1]=="s"&&s[N-1]=='o'&&ani1[N-2]==ani1[0])d=0;
    else if(ani1[N-1]=="s"&&s[N-1]=='x'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='o'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='x'&&ani1[N-2]==ani1[0])d=0;
    if(c==0&&d==0){
        for(ll i=0;i<N;i++){
            if(ani1[i]=="s")cout<<"S";
            else cout<<"W";
        ;}cout<<endl;return 0;
    }
    break;}

    while(1){
    vector<string> ani1(N,"?");
    ani1[0]="w";
    if(s[0]=='o'){
        ani1[N-1]="s";
        ani1[1]="w";
    }
    else {ani1[N-1]="s";
          ani1[1]="s";}
    for(ll i=2;i<=N-2;i++){
        if(ani1[i-1]=="s"){
            if(s[i-1]=='o'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='x'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
        else if(ani1[i-1]=="w"){
            if(s[i-1]=='x'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='o'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
    ;}
    bool c=1,d=1;
    if(ani1[N-2]=="s"&&s[N-2]=='o'&&ani1[N-3]==ani1[N-1])c=0;
    else if(ani1[N-2]=="s"&&s[N-2]=='x'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='o'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='x'&&ani1[N-3]==ani1[N-1])c=0;
    if(ani1[N-1]=="s"&&s[N-1]=='o'&&ani1[N-2]==ani1[0])d=0;
    else if(ani1[N-1]=="s"&&s[N-1]=='x'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='o'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='x'&&ani1[N-2]==ani1[0])d=0;
    if(c==0&&d==0){
        for(ll i=0;i<N;i++){
            if(ani1[i]=="s")cout<<"S";
            else cout<<"W";
        ;}cout<<endl;return 0;
    }break;}

    while(1){
    vector<string> ani1(N,"?");
    ani1[0]="w";
    if(s[0]=='o'){
        ani1[N-1]="w";
        ani1[1]="s";
    }
    else {ani1[N-1]="w";
          ani1[1]="w";}
    for(ll i=2;i<=N-2;i++){
        if(ani1[i-1]=="s"){
            if(s[i-1]=='o'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='x'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
        else if(ani1[i-1]=="w"){
            if(s[i-1]=='x'){ani1[i]=ani1[i-2];}
            else if(s[i-1]=='o'){
                if(ani1[i-2]=="s")ani1[i]="w";
                else ani1[i]="s";
            }
        }
    ;}
    bool c=1,d=1;
    if(ani1[N-2]=="s"&&s[N-2]=='o'&&ani1[N-3]==ani1[N-1])c=0;
    else if(ani1[N-2]=="s"&&s[N-2]=='x'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='o'&&ani1[N-3]!=ani1[N-1])c=0;
    else if(ani1[N-2]=="w"&&s[N-2]=='x'&&ani1[N-3]==ani1[N-1])c=0;
    if(ani1[N-1]=="s"&&s[N-1]=='o'&&ani1[N-2]==ani1[0])d=0;
    else if(ani1[N-1]=="s"&&s[N-1]=='x'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='o'&&ani1[N-2]!=ani1[0])d=0;
    else if(ani1[N-1]=="w"&&s[N-1]=='x'&&ani1[N-2]==ani1[0])d=0;
    if(c==0&&d==0){
        for(ll i=0;i<N;i++){
            if(ani1[i]=="s")cout<<"S";
            else cout<<"W";
        ;}cout<<endl;return 0;
    }break;}
    cout<<-1<<endl;
    return 0;
}
