#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int k;
    cin>>k;
    for (int i=0;i<s.size();i++) {
        if (i!=s.size()-1) {
            if (s[i]!='a') {
                if (27-(s[i]-96)<=k) {
                    k-=27-(s[i]-96);
                    s[i]='a';
                }
            }
        } else {
            k=k%26;
            int tmp=s[i]+k;
            if (tmp>122) {
                tmp-=26;
            }
            char c=tmp;
            s[i]=c;
        }
    }
    cout<<s<<endl;
}