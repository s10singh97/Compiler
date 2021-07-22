#include<bits/stdc++.h>
using namespace std;

bool inkey(string t, vector<string> ke)
{
    for(int i = 0; i < ke.size(); i++)
        if(t == ke[i])
            return true;
    return false;
}

bool insymbol(char c, vector<char> s)
{
    for(int i = 0; i < s.size(); i++)
        if(c == s[i])
            return true;
    return false;
}

int main()
{
    vector<string> ke{"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","volatile","do","if","static","while","asm","bool","catch","class","const_cast","delete","dynamic_cast","explicit","export","false","friend","inline","mutable","namespace","new","operator","private","protected","public","reinterpret_cast","static_cast","template","this","throw","true","try","typeid","typename","using","virtual","wchar_t"};
    map<string, int> kw;
    map<char, int> op;
    map<string, int>var;
    vector<char> s{'<','>','(',')','{','}',';','#','.'};
    map<char, int>sym;
    map<string, int>cost;
    ifstream ip;
    ip.open("1.txt");
    int tokens = 0;
    string t = "";
    while(ip)
    {
        string a;
        getline(ip, a);
        for(int i = 0; i < a.length(); i++)
        {
            // if(a[i] == '\"')
            // {
            //     while(a[i] != '\"')
            //     {
            //         t += a[i];
            //         i++;
            //     }
            //     cost[t]++;
            // }
            // t.clear();
            if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%' || a[i] == '=')
            {
                op[a[i]]++;
                continue;
            }
            if(insymbol(a[i], s))
            {
                sym[a[i]]++;
                continue;
            }
            if(a[i] != ' ')
                t += a[i];
            else
            {
                if(inkey(t, ke))
                    kw[t]++;
                else
                    var[t]++;
                t.clear();
            }
        }
    }
    cout<<"Keywords :\n";
    for(auto i = kw.begin(); i != kw.end(); i++)
        cout<<i -> first<<" : "<<i -> second<<"\n";
    cout<<"Operators :\n";
    for(auto i = op.begin(); i != op.end(); i++)
        cout<<i -> first<<" : "<<i -> second<<"\n";
    cout<<"Variables :\n";
    for(auto i = var.begin(); i != var.end(); i++)
        cout<<i -> first<<" : "<<i -> second<<"\n";
    cout<<"Symbols :\n";
    for(auto i = sym.begin(); i != sym.end(); i++)
        cout<<i -> first<<" : "<<i -> second<<"\n";
    return 0;
}
