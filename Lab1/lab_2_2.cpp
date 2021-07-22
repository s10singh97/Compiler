#include<bits/stdc++.h>
using namespace std;
int main(){
	string str,patt;
	cout<<"Enter the string :\n";
	getline(cin,str);
	cout<<"Enter the pattern :\n";
	getline(cin,patt);
	
	int ls,lp,i,j,start;
	ls = str.length();
	lp = patt.length();
	int pie[lp];
	pie[0] = 0;
	for(i=1,j=0;i<lp;i++){
		if(patt[i]==patt[j]){
			pie[i] = pie[i-1]+1;
			j++;
		}
		else
		{
			pie[i]=0;
			j=0;
		}
	}
	start = 0;
	i=start;
	j=0;
	bool matched = false;
	for(start = 0;start<ls-lp;start++){
		j = pie[j];
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
