#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    string t="";
    std::deque<string> words{"maerd","remaerd","esare","resare"};
    std::deque<string> deq{t};
    while (deq.size()!=0) {
        string tmp=deq.front();
        deq.pop_front();
        if (tmp.size()<100000) {
            for (int i=0;i<4;i++) {
                if (tmp+words[i]==s) {
                    cout<<"YES"<<endl;
                    return 0;
                } else if (tmp+words[i]==s.substr(0,(tmp+words[i]).size())) {
                    deq.emplace_back(tmp+words[i]);
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}