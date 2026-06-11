#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
 
    int n;
    cin>>n;

    string s;
    cin>>s;

    string t;
    cin>>t;

    int cnt;
    int max_cnt=0;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n-i;j++){
            if(s.at(i+j)==t.at(j))
                cnt++;
        }
        max_cnt=max(max_cnt,cnt);
    }

    cout<<2*n-max_cnt;

    return 0;
}   