#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(string a,string b)
{
    return a+b<b+a;
}
string a[110];
int main()
{
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    string str;
    for(int i=0;i<n;i++) str+=a[i];
    cout<<str<<endl;
}