#include <iostream>
//#include <iomanip>
#include <string>
//#include <algorithm>
//#include <utility>
//#include <stack>
//#include <queue>
//#include <tuple>
//#include <set>
//#include <map>
//#include <unordered_map>
#include <vector>
//#include <functional>
//#include <bitset>
//#include <cmath>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
#define MOD 1000000007

int main(){
    string s;
    cin >> s;

    bool chk[200001][26];
    vector<int> beg;
    int r=26,K=0;
    for(int i=0;i<26;i++) chk[s.size()][i]=false;

    for(int at=s.size()-1;at>=0;at--){
        for(int i=0;i<26;i++) chk[at][i]=chk[at+1][i];
        if(!chk[at][s[at]-'a']){
            chk[at][s[at]-'a']=true;
            r--;
        }
        if(r==0){
            r=26;
            for(int i=0;i<26;i++) chk[at][i]=false;
            K++;
            beg.push_back(at);
        }
    }

    string ans="";
    for(char c='a';c<='z';c++){
        if(!chk[0][c-'a']){
            ans=c;
            break;
        }
    }
    for(int i=beg.size()-1;i>=0;i--){
        char last=ans.back();
        int j;
        for(j=beg[i];s[j]!=last;j++);
        for(char c='a';c<='z';c++){
            if(!chk[j+1][c-'a']){
                ans=ans+c;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}