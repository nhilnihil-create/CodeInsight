#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int cnt = s.size();
    int i=0;
    while(cnt){
        if(s.substr(i,7)=="remaerd"){
            i += 7;
            if(cnt==i){
                puts("YES");
                return 0;
            }
        }else if(s.substr(i,6)=="resare"){
            i += 6;
            if(cnt==i){
                puts("YES");
                return 0;
            }
        }else if(s.substr(i,5)=="maerd"){
            i += 5;
            if(cnt==i){
                puts("YES");
                return 0;
            }
        }else if(s.substr(i,5)=="esare"){
            i += 5;
            if(cnt==i){
                puts("YES");
                return 0;
            }
        }else{
            puts("NO");
            return 0;
        }
    }
    return 0;
}