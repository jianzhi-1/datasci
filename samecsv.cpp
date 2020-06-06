#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
typedef pair<ll,ll> pi;
typedef vector<ll> vi;

vector<string> row, row2;

fstream fileone, filetwo;
string filenameone, filenametwo;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> filenameone >> filenametwo;
	fileone.open(filenameone, ios::in);
	filetwo.open(filenametwo, ios::in);
	string line, line2;
	while (fileone >> line && filetwo >> line2){
		if (line != line2){
			cout << "false" << endl;
			fileone.close();
			filetwo.close();
			return 0;
		}
	}
	cout << "true" << endl;
	
	fileone.close();
	filetwo.close();
}
