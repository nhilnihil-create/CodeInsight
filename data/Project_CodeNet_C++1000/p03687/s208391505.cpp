# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
set<char>SET;
bool valid(string s){
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;cin>>s;
    string ori=s;
    int mini=1e9;
    for(char isi:s){
        SET.insert(isi);
    }
    for(auto isi:SET){
        string temp;
        s=ori;
        int ans=0;
        while(!valid(s)){
            temp="";
            for(int i=0;i<(int)s.size()-1;i++){
                if(s[i]==isi || s[i+1]==isi) temp+=isi;
                else temp+=s[i];
            }
            ans++;
            s=temp;
        }
        mini=min(ans,mini);
    }
    cout<<mini<<endl;

}