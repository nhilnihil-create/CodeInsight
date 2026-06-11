#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string x;cin>>x;
    string::iterator sp=x.begin();
    string::iterator tp=x.begin();
    ++tp;
    while(tp!=x.end())
    {
        if(*sp!='S'||*tp!='T'){
            sp++;tp++;
        }else{
            x.erase(sp,tp+1);
            tp=sp;sp--;
        }
    }
    printf("%d",x.size());
    return 0;
}
/*

*/