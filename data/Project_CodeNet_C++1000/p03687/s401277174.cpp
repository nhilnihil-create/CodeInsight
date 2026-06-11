#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){
    string S;
    cin>>S;
    map<char, int> chrmap;
    vector<char> chrarr;
    for(int i=0;i<S.size();++i){
        if(chrmap[S[i]]==0)chrarr.push_back(S[i]);
        chrmap[S[i]]++;
    }
    char tmp;
    string tmpstr, tmptmpstr;
    int ans = 10000;
    bool ok;
    if(chrarr.size()==1)cout<<0<<endl;
    else{
    for(int i=0;i<chrarr.size();++i){
        tmp = chrarr[i];
        tmpstr = S;
        while(true){
            ok = true;
            tmptmpstr = "";
            for(int j=0;j<tmpstr.size()-1;++j){
                if(tmpstr[j]==tmp | tmpstr[j+1]==tmp){
                    tmptmpstr += tmp;
                }
                else{
                    ok = false;
                    tmptmpstr += 'A';
                }
            }
            if(ok)break;
            tmpstr = tmptmpstr;
        }
        if(ans > S.size() - tmpstr.size()) ans = S.size() - tmptmpstr.size();
    }
    cout<<ans<<endl;
    }
}
