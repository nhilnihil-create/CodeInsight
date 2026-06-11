#include <iostream>

using namespace std;

int main()
{
    string sa, sb, sc;
    cin >> sa;
    cin >> sb;
    cin >> sc;
    int flag = 1;
    if(sa.size()<1 || sa.size()>100)flag = 0;
    if(sb.size()<1 || sb.size()>100)flag = 0;
    if(sc.size()<1 || sc.size()>100)flag = 0;

    if(flag)
    {
        for(int i =0; i<sa.size(); i++)
        {
            if(sa[i]!='a' && sa[i] != 'b' && sa[i] != 'c') flag = 0;
        }
        for(int i =0; i<sb.size(); i++)
        {
            if(sb[i]!='a' && sb[i] != 'b' && sb[i] != 'c') flag = 0;
        }
        for(int i =0; i<sc.size(); i++)
        {
            if(sc[i]!='a' && sc[i] != 'b' && sc[i] != 'c') flag = 0;
        }
    }

    int winnn=0;
    int turn = 0;
    while(winnn == 0 && flag == 1)
    {
        if(turn == 0)
        {
           if(sa.size()>0){
                turn = int(sa[0])-97;
                sa.erase(sa.begin());

            }
            else {
                cout << "A" << endl;
                winnn = 1;
            }
        }
        else if(turn == 1)
        {
            if(sb.size()>0){
                turn = int(sb[0])-97;
                sb.erase(sb.begin());

            }
            else {
                cout << "B" << endl;
                winnn = 1;

            }
        }
        else if(turn == 2)
        {
            if(sc.size()>0){
                turn = int(sc[0])-97;
                sc.erase(sc.begin());


            }
            else {
                cout << "C" << endl;
                winnn = 1;

            }
        }
    }
    return 0;
}
