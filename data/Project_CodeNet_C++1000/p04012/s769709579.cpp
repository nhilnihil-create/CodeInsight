#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[106];

    cin>>str;

    int n = strlen(str) , i;

    int cnt[26] = {0} ;

    for(i = 0 ; i < n ; i++){
        cnt[str[i]-'a']++;
    }

    bool ok = 1;

    for(i = 0 ; i < 26 ; i++){
        if(cnt[i]%2 != 0){
            ok = 0;
            break;
        }
    }

    if(ok)  cout<<"Yes\n";
    else cout<<"No\n";

    return 0;

}
