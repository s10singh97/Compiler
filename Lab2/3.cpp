#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    bool flag_b = false, over = false;
    if(s.length() == 0)
    {
        over = true;
        if(over)
        cout<<"Acceptable\n";
        else
            cout<<"Not acceptable\n";
        return 0;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a' || s[i] == 'b')
        {
            if(s[i] == 'b')
            {
                flag_b = true;
                continue;
            }
            if(s[i] == 'a' && !flag_b)
                over = true;
            else if(flag_b && s[i] == 'b')
                over = true;
            else
                over = false;
        }
        else
            over = false;
    }
    if(over)
        cout<<"Acceptable\n";
    else
        cout<<"Not acceptable\n";
    return 0;
}