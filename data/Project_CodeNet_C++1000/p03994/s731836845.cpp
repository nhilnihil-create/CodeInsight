#include <iostream>
using namespace std;

int main(){
    string s;
    int k;
    cin>>s>>k;

    for(int i=0; i<(int)s.size(); i++){
        if(k >= ('z' - s[i] + 1) && s[i] != 'a'){
            k -= ('z' - s[i] + 1);
            s[i] = 'a';
        }
    }

    k %= 26;
    int ende = (int)s.size()-1;
    for(int i=0; i<k; i++){
        if(s[i] == 'z') s[i] = 'a';
        s[ende]++;
    }

    cout<<s<<endl;
}
