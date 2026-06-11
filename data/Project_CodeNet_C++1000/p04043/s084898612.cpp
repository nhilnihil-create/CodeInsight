    #include <bits/stdc++.h>
    using namespace std;
     
    int main() 
	
	{
        int a, b, c;
        int cnt5 = 0;
        int cnt7 = 0;
     
     
        cin >> a >> b >> c;
        
        if (a == 5) 
            cnt5++;
        
        else if (a == 7) 
            cnt7++;
        
        
        if (b == 5) 
            cnt5++;
        
        else if (b == 7) 
            cnt7++;
        
     
        if (c == 5) 
            cnt5++;
        
        else if (c == 7) 
            cnt7++;
        
     
        if (cnt5 == 2 && cnt7 == 1) 
            cout << "YES" << endl;
        
        else 
            cout << "NO" << endl;
        
     
    }