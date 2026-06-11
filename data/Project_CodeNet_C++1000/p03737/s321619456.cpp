#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    string s,a,b,c;
    s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin>>a>>b>>c;
    cout<<s[a[0]-'a']<<s[b[0]-'a']<<s[c[0]-'a']<<endl;
    return 0;
}
