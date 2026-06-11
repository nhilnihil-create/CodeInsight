#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli k;
    string s;
    vector<lli> num;
    lli i,j=0;
    cin>>s>>k;
    while(k!=0){
//        cout<<j+1<<"番目の文字について"<<endl;
        if(j!=s.size()-1){
            if(26-(s[j]-'a')<=k){
                if(s[j]!='a'){
                    k-=26-(s[j]-'a');
//                    cout<<s[j]<<"をaに変える"<<endl;
                    s[j]='a';
                }
            }
            j++;
        }
        else{
            if(26-(s[j]-'a')>k){
//                cout<<s[j]<<"を";
                s[j]+=k;
//                cout<<s[j]<<"に変える"<<endl;
            }
            else{
//                cout<<s[j]<<"を";
                k-=26-(s[j]-'a');
                s[j]='a'+k%26;
//                cout<<s[j]<<"に変える"<<endl;
            }
            k=0;
        }
    }
    cout<<s<<endl;
}
