#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
static const int MOD=1000000007;

int main(){
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    ll ans;
    bool check=true;
    if(s1[0]==s2[0]){
        ans=3;
    }else{
        ans=6;
        check=false;
    }
    if(check){
        bool checkX=true;
        for(int i=1;i<s1.size();i++){
            if(checkX){
                if(s1[i]==s2[i]){
                    ans*=2;
                }else{
                    checkX=false;
                    ans*=2;
                    i++;
                }
                ans%=MOD;
            }else{
                if(s1[i]!=s2[i]){
                    ans*=3;
                    i++;
                }else{
                    checkX=true;
                }
                ans%=MOD;
            } 
        }
    }else{
        bool checkX=false;
        for(int i=2;i<s1.size();i++){
            if(checkX){
                if(s1[i]==s2[i]){
                    ans*=2;
                }else{
                    checkX=false;
                    ans*=2;
                    i++;
                }
                ans%=MOD;
            }else{
                if(s1[i]!=s2[i]){
                    ans*=3;
                    i++;
                }else{
                    checkX=true;
                }
                ans%=MOD;
            } 
        }
    }
    cout << ans << endl;
}