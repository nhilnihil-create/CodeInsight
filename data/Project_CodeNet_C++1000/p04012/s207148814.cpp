                                         //BISMILLAHIR RAHMANIR RAHIM
                                          //By the name of ALLAH
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<numeric>
#define pi acos(-1.0)
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int l=s.size();
    sort(s.begin(),s.end());
            int i,j,c;
       for(i=0;i<l;){
            c=1;
        for(j=i;j<l;j++){
            if(s[j]==s[j+1]){
                c++;
            }
            else
            break;
        }
        if(c%2!=0)
            break;
        else
            i=i+j+1;
       }
       if(c%2!=0)
       cout<<"No"<<endl;
       else
        cout<<"Yes"<<endl;

}
int main()
{
    solve();
    return 0;
}
