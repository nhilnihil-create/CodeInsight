#include<bits/stdc++.h>
#define mp make_pair
#define endl "\n"
#define v vector
#define b begin()
#define e end()
using namespace std;
typedef long long ll;
typedef long l;
typedef long long unsigned ull;

int main(){

    int n;
    string s;
    cin>>n>>s;
    int x=0,max_num = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'I'){
            x++;
        }
        else{
            x--;
        }
        if(x>max_num){
            max_num = x;
        }
    }
    cout<<max_num;
    return 0;

}
