#include<bits/stdc++.h>
using namespace std;

void print(map<char, string> &mp)
{
	map<char, string>::iterator i; 
    for(i = mp.begin(); i != mp.end(); i++)
        cout<<i -> first<<" -> "<<i -> second<<"\n";
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
    map<char, string> mp;
    for(int i = 0; i < n; i++)
        mp[p[i].first] = p[i].second;

    vector<string> fir;
    map<char, string>::iterator i;
    for(i = mp.begin(), int j = 0; i != mp.end(); i++)
    {
        string rear = i -> second;
        if(rear[j] >= 'A' && rear[j] <= 'Z')
            first(rear[j+1]);
    }    


    // print(mp);
    return 0;
}
