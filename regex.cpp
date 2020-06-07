#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define VREP(it, v) for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
#define SVREP(it, v) for (vector<string>::iterator it = v.begin(); it != v.end(); it++)

typedef pair<ll,ll> pi;
typedef vector<ll> vi;

//exactly one lowercase char 			: [a-z]
//an alphanumeric char					: [A-Za-z0-9]
//any lowercase string except blank		: [a-z]+
//any lowercase string incl blank		: [a-z]*
//repeated pattern						: (Xyz)+
string str;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;
	regex b("(.*)(hello)(.*)");
	
	cout << regex_match(str, b) << endl;
	cout << regex_match(str.begin(), str.begin() + str.length()/2, b) << endl;
	
	
}
