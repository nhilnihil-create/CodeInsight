#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main(void){
    int i,j;
    string s;
    cin >> s;
    long long ans=0;
    for(i=0;i<1<<(s.size()-1);i++){
        long long tmp = s[0]-'0';
        for(j=0;j<s.size()-1;j++){
            if(i&(1<<j)){
                ans += tmp;
                tmp = (s[j+1]-'0');
            }
            else{
                tmp = tmp*10+(s[j+1]-'0');
            }
        }
        ans += tmp;
    }
    cout << ans << endl;
}