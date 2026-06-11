#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    string s;
    cin >> s;
    int K;
    cin >> K;

    for(int i=0; i<(int)s.size() && K>0; i++){
        int diff='z'-s[i]+1;
        if(s[i]=='a'){
            continue;
        }else if(diff<=K){
            s[i]='a';
            K-=diff;
        }else if(i==(int)s.size()){
            s[i]+=K;
            K=0;
        }
    }
    if(K>0){
        s[(int)s.size()-1]+=(K%26);
        K=0;
    }
    cout << s << '\n';
}