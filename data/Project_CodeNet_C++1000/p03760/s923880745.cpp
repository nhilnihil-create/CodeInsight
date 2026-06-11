#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int a = 0 ,b = 0 ;
	string s1,s2;
	cin >> s1 >> s2 ;
	for(int cnt = 0 ,a=0,b=0; a<s1.size() || b<s2.size(); cnt++ )
    {
        if(cnt%2==0)
        {
            cout << s1[a++] ;
        }
        else
            cout << s2[b++] ;
    }
    cout << endl;

}
