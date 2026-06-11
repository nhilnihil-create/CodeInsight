#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    char a;
    string s;
    int i, cnt = 0;
    cin>>s;
    for(i = 0; i<s.size()-1; i++)
    {
        a = s[i];
        if(s[i+1] != a) cnt++;
    }
    cout<<cnt<<endl;

    return 0;

}
