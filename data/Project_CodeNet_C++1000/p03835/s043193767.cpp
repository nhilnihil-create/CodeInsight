#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define endll "\n"

#define fin             freopen("input.txt","r",stdin);
#define fout            freopen("output.txt","w",stdout);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,s,c=0;
    cin >> k >> s;

    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            if(s-(i+j)>=0 && s-(i+j)<=k){
                c++;
            }
        }
    }
    cout << c << endl;

    return 0;
}

