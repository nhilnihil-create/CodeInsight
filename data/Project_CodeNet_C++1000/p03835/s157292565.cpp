#include<bits/stdc++.h>
#define int long long
#define log(x,b) (log(x)/log(b))
using namespace std;

string s[101];

int32_t main()
{
    int k,s;
    cin>>k>>s;

    int cnt=0;
    for(int i=0;i<k+1;i++){
        for(int j=0;j<k+1;j++){
            int p=s-i-j;
            if(p>=0&&p<=k)cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
