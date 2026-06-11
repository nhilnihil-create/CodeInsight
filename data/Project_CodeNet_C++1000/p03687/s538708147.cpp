#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;   cin >> s;
    set<char> obj;
    for(int i=0; i<s.size(); i++)   obj.insert(s.at(i));
    ll cnt=0, res=1e+10;
    if(obj.size()==1) res=0;

    for(auto c: obj){
        string str=s;
        bool f = true;
        cnt = 1;
        while(f){
            f = false;
            string tmp;
            for(int i=0; i<str.size()-1; i++){
                if(str.at(i)==c || str.at(i+1)==c) tmp += c;
                else{
                    tmp += s.at(i); f = true;
                }
            }
            if(f){
                str = tmp; cnt += 1;
            }
            
        }
        res = min(cnt, res);
    }
    cout << res << endl;

}