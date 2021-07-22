// Operator Precedence Parser

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of Productions: ";
    cin>>n;
    cout<<"Enter Productions: \n";
    string s[n];
    for(int i = 0; i < n; i++)
        cin>>s[i];
    set<char> nt;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < s[i].length(); j++)
        {
            if(!isupper(s[i][j]) && s[i][j] != '=' && s[i][j] != '/')
                nt.insert(s[i][j]);
        }
    }
    nt.insert('$');
    // for(auto i = nt.begin(); i != nt.end(); i++)
    //     cout<<*i<<" ";
    map<char, int>pre;
    // pre[0] = '$';
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < s[i].length(); j++)
        {
            if(!isalpha(s[i][j]) && s[i][j] != '=' && s[i][j] != '/')
                pre[s[i][j]] = k++;
        }
    }
    // for(auto i = pre.begin(); i != pre.end(); i++)
    // {
    //     for(int j = 0; j < (i -> second).size(); j++)
    //         cout<<i -> second[j]<<" ";
    //     cout<<"\n";
    // }
    vector<char> v(nt.begin(), nt.end());
    // for(int i = 0; i < nt.size(); i++)
    //     cout<<v[i]<<" ";
    int p = 0, q = 0;
    char tab[nt.size()+1][nt.size()+1];
    for(int i = 0; i < nt.size()+1; i++)
    {
        for(int j = 0; j < nt.size()+1; j++)
        {
            if(i == 0 && j != 0)
                tab[i][j] = v[p++];
            else if(j == 0 && i != 0)
                tab[i][j] = v[q++];
            else if(i == 0 && j == 0)
                tab[i][j] = '@';
            else
            {
                if(isalpha(v[i-1]) && isalpha(v[j-1]))
                    tab[i][j] = '-';
                else if(isalpha(v[i-1]) && !isalpha(v[j-1]))
                    tab[i][j] = '>';
                else if(isalpha(v[j-1]) && !isalpha(v[i-1]))
                    tab[i][j] = '<';
                else if(v[i-1] == '$' && v[j-1] == '$')
                    tab[i][j] = '-';
                else if(v[i-1] == '$')
                    tab[i][j] = '<';
                else if(v[j-1] == '$')
                    tab[i][j] = '>';
                else if(pre[v[i]] > pre[v[j]])
                    tab[i][j] = '>';
                else if(pre[v[i]] < pre[v[j]])
                    tab[i][j] = '<';
            }
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}