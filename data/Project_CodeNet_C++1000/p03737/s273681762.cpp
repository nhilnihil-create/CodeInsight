#include<iostream>
using namespace std;
int main()
{
    string s1,s2,s3,a,A;
    cin>>s1>>s2>>s3;
    string ans;
    ans += (char) (s1[0]-'a'+'A');
    ans += (char) (s2[0]-'a'+'A');
    ans += (char) (s3[0]-'a'+'A');

    cout<<ans<<endl;
    return 0;
}
