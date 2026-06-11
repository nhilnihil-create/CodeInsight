#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    long K;
    cin>>s;
    cin>>K;
    for(long i=0;i<s.size();++i){
        if((K >= 'z' - s[i] + 1) & (s[i]!='a')){
            K -= 'z' - s[i] + 1;
            s[i] = 'a';
        }
        if(K==0)break;
    }
    if(K>0){
        s[s.size()-1] += K % 26;
        while(s[s.size()-1] > 'z'){
            s[s.size()-1] -= 'a';
        }
    }
    cout<<s<<endl;
}
