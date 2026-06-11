#include <bits/stdc++.h>
using namespace std;

int a[26];
int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++) a[s[i]-'a']++;
    int b=0;
    for(int i=0;i<26;i++){
        if(a[i]>0) b++;
    }
    if(b==1){
        cout << 0 << endl;
        return 0;
    }
    long long res=100000;
    for(int i=0;i<26;i++){
        if(a[i]>0){
            long long count=0;
            string str=s;
            while(1){
                count++;
                for(int j=0;j<s.size()-1;j++){
                    if(str[j]!='a'+i&&str[j+1]=='a'+i) str[j]='a'+i;
                }
                str[s.size()-count]='A';
                bool flag=true;
                for(int j=0;j<s.size();j++){
                    if(str[j]=='a'+i||str[j]=='A') continue;
                    else flag=false;
                }
                if(flag) break;
            }
            res=min(res,count);
        }
    }
    cout << res << endl;
}
