    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        int n, a, b, passed = 0, os = 0;
        string input;
     
        cin >> n >> a >> b >> input;
     
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == 'a')
            {
                if(passed < a + b)
                {
                    cout << "Yes" << "\n";
                    passed++;
                }
                else
                    cout << "No" << "\n";
            }
     
            else if(input[i] == 'b')
            {
                if(passed < a + b)
                {
                    if(os < b)
                    {
                        cout << "Yes" << "\n";
                        os++;
                        passed++;
                    }
     
                    else
                        cout << "No" << "\n";
                }
     
                else
                {
                    cout << "No" << "\n";
                }
                
            }
     
            else
            {
                cout << "No" << "\n";
            }
      
        }
    }