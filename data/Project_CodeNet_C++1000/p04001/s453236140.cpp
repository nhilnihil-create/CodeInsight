#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    vector<long long> v;
    for (long long i = 0;i < s.size();i++){
        v.push_back(s[i]-'0');
    }
    long long ans = 0;
    for (long long i = 0;i < (1<<(v.size()-1));i++){
        stack<long long> S;
        S.push(v[0]);
        for (long long j = 0;j < v.size();j++){
            if ((i>>j)%2==0 && j != v.size()-1){
                S.push(v[j+1]);
            }
            else {
                long long p = 1;
                while(S.size()!=0){
                    long long t = S.top();
                    S.pop();
                    ans += t*p;
                    p *= 10;
                }
                S.push(v[j+1]);
            }
        }
    }
    cout << ans << endl;
}
