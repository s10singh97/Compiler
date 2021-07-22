#include<bits/stdc++.h>
using namespace std;
E() 
{ 
	if (l == 'i') 
    { 
		match('i'); 
		E'(); 
	} 
}
E'() 
{ 
	if (l == '+') { 
		match('+'); 
		match('i'); 
		E'(); 
	} 
	else
		return (); 
} 
match(char t) 
{ 
	if (l == t) { 
		l = getchar(); 
	} 
	else
		printf("Error"); 
} 
int main() 
{ 
	E();  
	if (l == '$') 
		printf("Parsing Successful"); 
} 





