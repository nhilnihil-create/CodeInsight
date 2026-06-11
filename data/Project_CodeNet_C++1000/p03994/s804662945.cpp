#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
    string s;
    int k;
    cin>>s>>k;

    for(int i=0;i<s.length();i++){
        if(s[i] == 'a') continue;
        if( ( 'z' - s[i] +1 ) <= k ){
            k = k - ('z'-s[i]+1);
            s[i] = 'a';
        }
        if(k == 0) break;
    }

    if(k>0){
        s[s.length()-1] = s[s.length()-1] + (k%26);
    }

    cout<<s<<endl;

}