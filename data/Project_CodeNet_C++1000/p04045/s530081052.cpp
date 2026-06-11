#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<bool> avail = {false, false, false, false, false, false, false, false, false, false};
    string N;
    int D;
    string res = "";
    cin >> N >> D;
    int MIN = 0;
    for (int i = 0; i < D; i++)
    {
        int a;
        cin >> a;
        avail[a] = true;
    }
    for (int i = 0; i < avail.size(); i++)
    {
        if (avail[MIN] == true)
        {
            MIN = MIN + 1;
        }
        else
        {
            break;
        }
    }

    bool new_size = false;
    bool test = false;
    for (int i = 0; i < N.size(); i++)
    {
        if (test == true)
        {
            res += to_string(MIN);
        }
        else if (new_size == false)
        {
            if (int(N[i] - 48) == 9 && avail[int(N[i] - 48)])
            {
                new_size = true;
                if (MIN == 0)
                {
                    for (int a = MIN + 1; a < avail.size(); a++)
                    {
                        if (!avail[a])
                        {
                            res += to_string(a);
                            test = true;
                            break;
                        }
                    }
                }
                else
                {
                    res += to_string(MIN);
                }
            }
            else if (!avail[int(N[i] - 48)])
            {
                res += to_string(int(N[i] - 48));
            }
            else
            {
                bool t = false;
                for (int a = int(N[i] - 48) + 1; a < avail.size(); a++)
                {

                    if (!avail[a])
                    {
                        t = true;
                        res += to_string(a);
                        test = true;
                        break;
                    }
                }
                if (!t)
                {
                    new_size = true;
                    res += to_string(MIN);
                    
                }
            }
        }
        else
        {
            res += to_string(MIN);
        }
    }

    if (new_size == true)
    {
        res += to_string(MIN);
    }
    cout << stoi(res) << endl;
}
