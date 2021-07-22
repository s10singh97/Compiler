#include<bits/stdc++.h>
using namespace std;
int main(){
	string str,patt;
	cout<<"Enter the string : \n";
	getline(cin,str);
	cout<<"Enter the pattern to be searched :\n";
	getline(cin,patt);
	
	int ls,lp,i,j,start;
	bool matched = false;
	ls = str.length();
	lp = patt.length();
	start = 0;
	i=start;
	j=0;
	for(start = 0;start<ls-lp;start++){
		i = start;
		while(i<ls){
			if(str[i]==patt[j])
			{
				i++;
				j++;
				if(j==lp){
					matched = true;
					break;
				}
			}
			i++;
		}
		if(matched)
		break;
	}
	if(matched){
		cout<<"Pattern matched from index "<<(i-j);
	}
	else
	cout<<"Pattern not matched";
}
