#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    bool flag = false;
    if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || (s[0] == '_' && (s[1] >= 'a' && s[1] <= 'z') || (s[1] >= 'A' && s[1] <= 'Z')))
        flag = true;
    if(flag)
        cout<<"It is an Identifier\n";
    else
        cout<<"Not an Identifier\n";

    return 0;
}
