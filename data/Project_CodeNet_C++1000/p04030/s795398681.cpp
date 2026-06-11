#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string strr;
    cin >> strr;
    if(strr.size()>0 && strr.size()<11)
    {
        string answer;
        int i = 0;
        while(i<strr.size())
        {
            if(strr[i]!='B')
            {
                answer+=strr[i];
                i++;
            }
            else
            {
                if(answer.size()==0){
                    i++;
                }
                else {
                    answer.erase(answer.size()-1);
                    i++;
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}