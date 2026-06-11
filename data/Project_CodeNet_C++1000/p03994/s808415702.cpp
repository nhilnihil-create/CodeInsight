#include<bits/stdc++.h>
using namespace std;

// function implementing greedy approach
void smallest_string(string s , int m)
{
    int  n = s.size();   // size of the given string
    int a[n];        // declaring an array a 
    
    // for each i , a[i] contain number of operations to update s[i] to 'a' 
    for(int i = 0; i < n ; i++)
    {
        int distance = s[i]-'a';
        if(distance == 0)
        {
            a[i]=0;
        }
        else
        {
            a[i] = 26 - distance;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        // if m >= ar[i] , then update s[i] to 'a' decrement k by a[i]
        if(m >= a[i])
        {
            s[i] = 'a';
            m = m - a[i];
        }
        
    }
    
    //cycle of 26 
    m = m % 26;
    
    // update last element of string with the s[i] + (k % 26) 
    s[n-1] = s[n-1] + m;
    
    cout<<s<<endl;
    
}

//driever code
int main()
{
    //string str = "bazzzx";
    //int m = 10;
    string str;
    cin>>str;
    int m;
    cin>>m;
    smallest_string(str , m);
    return 0;
}
