#include<bits/stdc++.h>
using namespace std;

void print(vector<pair<char, string> >&p)
{
    for(int i = 0; i < p.size(); i++)
    {
        cout<<p[i].first<<" -> "<<p[i].second<<"\n";
    }
}

char first(char ele, vector<pair<char, string> >&p)
{
    if(ele >= 'a' && ele <= 'z')
        return ele;
}

int main()
{
    int n;
    cout<<"Enter number of production rules : ";
    cin>>n;
    string s[n];
    vector<pair<char, string> >p;
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
        pair<char, string> t;
        char ff = s[i][0];
        string rr = "";
        for(int j = 0; j < s[i].length(); j++)
        {
            if(s[i][j] == '=')
            {
                while(j+1 < s[i].length())
                {
                    rr.push_back(s[i][j+1]);
                    j++;
                }
                t = make_pair(ff, rr);
                break;
            }
        }
        p.push_back(t);
    }
    vector<string> fir;
    for(int i = 0; i < n; i++)
    {
        string rear = p[i] -> second;
        fir.push_back(first(rear[0], p));
    }    
    for(int i = 0; i < n; i++)
    {
        cout<<fir[i]<<"\n";
    }







    // for(int i = 0; i < n; i++)
    // {
    //     pair<char, string> t;
    //     for(int j = 0; j < s[i].length(); j++)
    //     {
    //         char ff = s[i][0];
    //         string rr = "";
    //         if(s[i][j] == '=' && s[i][j+1] == ' ')
    //         {
    //             while(j+2 < s[i].length())
    //             {
    //                 rr.push_back(s[i][j+2]);
    //                 j++;
    //             }
    //             t = make_pair(ff, rr);
    //             break;
    //         }
    //     }
    //     p.push_back(t);
    // }
    // print(p);
    // pair<char, string> t;
    //     char ff = s[i][0];
    //     string rr = "";
    //     for(int j = 0; j < s[i].length(); j++)
    //     {
    //         if(s[i][j] == '=' && s[i][j+1] == ' ')
    //         {
    //             while(j+2 < s[i].length())
    //             {
    //                 rr.push_back(s[i][j+2]);
    //                 j++;
    //             }
    //             t = make_pair(ff, rr);
    //         }
    //         break;
    //     }
    //     p.push_back(t);
    return 0;
}

