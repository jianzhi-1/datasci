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

vector<string> row;

// Function converting datatypes
// int -> string		: string str = to_string(int);
// string -> int		: int i = stoi(str);
// string -> double		: double d = stod(str);
// double -> string		: string str = to_string(d);


//breaking up a string by delimiter

string toBeSplit = "";
vector<string> res;
void split_string_by_space(char delimiter){
	res.clear();
	string cur = "";
	REP(i, 0, toBeSplit.length()){
		if (toBeSplit[i] != delimiter){
			cur = cur + toBeSplit[i];
		} else {
			if (cur != ""){
				res.push_back(cur);
				cur = "";
			}
		}
	}
	if (cur != ""){
		res.push_back(cur);
	}
}

void read_record(){
	//file pointer
	fstream fin;
	fin.open("reportcard.csv", ios::in);
	
	string line, temp, word;
	while (fin >> temp){
		row.clear();
		//used for breaking words using the delimiter
		//of ','
		stringstream s(temp);
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		//now all the words are placed in row
	}
	fin.close();
}

void update_record(){
	fstream fin, fout;
	fin.open("reportcard.csv", ios::in);
	fout.open("reportcardnew.csv", ios::out);
	
	vector<string> row;
	string line, word;
	
	while (!fin.eof()){
		row.clear();
		getline(fin, line);
		stringstream s(line);
		
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		
		fout << "insert your own function" << ",";
		fout << "\n";
	}
	
	fin.close();
	fout.close();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
	
