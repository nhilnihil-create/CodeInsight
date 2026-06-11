#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
ll table[1000][1000];
const ll mod =1000000007;

int main(){
    string s;
    cin >> s;
    int st=-1;
    int end=-1;
    for (int i =0;i < s.size();i++){
        if (i+1 < s.size()){
            if (s[i]==s[i+1]){
                st=i;
                end=i+1;
                break;
            }
        }
        if (i+2 < s.size()){
            if (s[i]==s[i+2]){
                st=i;
                end=i+2;
                break;
            }
        }
    }
    if (st==-1 && end==-1){
        cout << -1 << " " << -1 << endl;
    }
    else{
        st++;end++;
        cout << st  << " " << end << endl;
    }
    return 0;
}
