#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int now=0;
    int rank=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a' && now<a+b)
        {
            cout<<"Yes"<<"\n";
            now++;
        }
        else if(s[i]=='b' && now<a+b && rank<=b)
        {
            cout<<"Yes"<<"\n";
            now++;
            rank++;
        }
        else
        cout<<"No"<<"\n";

    }
    
}