#include<bits/stdc++.h>
using namespace std;
int lookahead = 0;
string s;
vector<string> v;

void E(); void Ep(); void T(); void Tp(); void F();

bool isIden(string s)
{
    vector<string> ke{"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","volatile","do","if","static","while","asm","bool","catch","class","const_cast","delete","dynamic_cast","explicit","export","false","friend","inline","mutable","namespace","new","operator","private","protected","public","reinterpret_cast","static_cast","template","this","throw","true","try","typeid","typename","using","virtual","wchar_t"};
    for(int i = 0; i < ke.size(); i++)
        if(s == ke[i])
            return false;
    if(s[0] >= '0' && s[0] <= '9')
        return false;
    return true;
}

void match(string c)
{
    if(v[lookahead] == c)
        lookahead++;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void E()
{
    if(v[lookahead] == "(" || isIden(v[lookahead]))
    {
        T();
        Ep();
        match("$");
    }
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void Ep()
{
    if(v[lookahead] == "+")
    {
        match("+");
        T();
        Ep();
    }
    else if(v[lookahead] == "$")
        return;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void T()
{
    if(v[lookahead] == "(" || isIden(v[lookahead]))
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
    if(v[lookahead] == "*")
    {
        match("*");
        F();
        Tp();
    }
    else if(v[lookahead] == "$" || v[lookahead] == "+")
        return;
    else
    {
        cout<<"Error\n";
        exit(0);
    }
}

void F()
{
    if(isIden(v[lookahead]))
    {
        match(v[lookahead]);
    }
    else if(v[lookahead] == "(")
    {
        match("(");
        E();
        match(")");
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
    int start = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '+' || s[i] == '*' || s[i] == '$')
        {
            v.push_back(s.substr(start, i-start));
            start = i+1;
        }
    }
    v.push_back("$");
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<"\t";
    E();
    cout<<"Accepted";
    return 0;
}
