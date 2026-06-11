#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
bool sme(string s){
    bool ans =true;
    fo(j,s.size()){
        if(s[j]!=s[0]){ans =false;break;}
    }
    return ans;
}
int main(){
    string s;cin >>s;
    int n =s.size(),minc;
    fo(k,26){
        int cnt = 0;
        string p =s;
        char cur(97+k);
        while(!sme(p)){
            tr(it,p){
                if(*it==cur||*(it+1)==cur){
                    *it = cur;
                }
            }
            p.resize(p.size()-1);           
            ++cnt;
        }
        if(k==0){
            minc = cnt;
        }
        else{
            (cnt<minc)?minc =cnt:minc =minc;
        }
    }
    cout << minc;
}