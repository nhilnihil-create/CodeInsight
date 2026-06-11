  #include<bits/stdc++.h>
    #define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
    #define ll long long
    #define ara(A,N) sort(A,A+N)
    #define rev(A,N) sort(A,A+N,greater<long long>())
    using namespace std;
    int main()
{
set<char>s;
int f=0;
string p;
char x;
char i;
cin>>p;
for(i='a';i<='z';i++)
{
    if(p.find(i)==string::npos)
    {    f=1;
        break;
    }
}
if(f)
cout<<i<<endl;
else
{
    cout<<"None"<<endl;
}
}
