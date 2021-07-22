#include<bits/stdc++.h>
using namespace std;
int lookahead = 0;
string s;

void E(); void Ep(); void T(); void Tp(); void F();

void match(char c)
{
    if(s[lookahead] == c)
        lookahead++;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void E()
{
    if((s[lookahead] >= '0' && s[lookahead] <= '9') || s[lookahead] == '(')
    {
        T();
        Ep();
        match('$');
    }
    //else if(s[lookahead] == '$' || s[lookahead] == ')')
    //    return;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void Ep()
{
    if(s[lookahead] == '+')
    {
        match('+');
        T();
        Ep();
    }
    else if(s[lookahead] == '$' || s[lookahead] == ')')
        return;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void T()
{
    if((s[lookahead] >= '0' && s[lookahead] <= '9') || s[lookahead] == '(')
    {
        F();
        Tp();
    }
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void Tp()
{
    if(s[lookahead] == '*')
    {
        match('*');
        F();
        Tp();
    }
    else if(s[lookahead] == ')')
        return;
    else if(s[lookahead] == '$' || s[lookahead] == '+')
        return;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void F()
{
    if(s[lookahead] >= '0' && s[lookahead] <= '9')
    {
        match(s[lookahead]);
    }
    else if(s[lookahead] == '(')
    {
        match('(');
        E();
        match(')');
    }
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

int main()
{
    cout<<"Enter the input string: ";
    cin>>s;
    s.push_back('$');
    E();
    cout<<"Accepted";
    return 0;
}
