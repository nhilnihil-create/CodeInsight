#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
string s;


int main(void)
{
    
    cin>>s;
    ll i=s.size()-1;

    while(i>0)
    {
        if(s.substr(i-4,5)=="dream") i-=5;
        else if(s.substr(i-4,5)=="erase") i-=5;
        else if(s.substr(i-5,6)=="eraser") i-=6;
        else if(s.substr(i-6,7)=="dreamer") i-=7;

        else
        {
            
            cout<<"NO"<<endl;
            return 0;
        }
        


    }
    cout<<"YES"<<endl;


}