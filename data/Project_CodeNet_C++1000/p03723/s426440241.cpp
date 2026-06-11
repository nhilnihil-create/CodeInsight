    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<bits/stdc++.h>
    #include<sstream>
     
    using namespace std;
     
    int main()
    {
        long long a, b, c, count = 0;

        cin >> a >> b >> c;

        if(a == b && b == c && a == c)
        {
            if(a%2 == 0)
                cout << -1;
            else
            {
                cout << 0;
            }
            
        }
        
        else
        {
            while(a%2==0 && b%2==0 && c%2==0)
            {
                long long d,e,f;

                d = a;
                e = b;
                f = c;

                a = e/2 + f/2;
                b = d/2 + f/2;
                c = d/2 + e/2;

                count++; 
            }

            cout << count;
        }
    
    } 