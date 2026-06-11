#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
using ll = long long;
int MOD = 1e9 + 7;
using namespace std;
int main()
{
    string s;
    int sum=0;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='p'){
                sum--;
            }
        }else{
            if(s[i]=='g'){
                sum++;
             //   cout<<"足す"<<endl;
            }
        }
    }
    cout<<sum<<endl;
}
