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

fstream bank, credit, device, order, answer;

int counter = 0; //number of unique buyer or seller
map<string, int> m; //maps buyer_id to counter;
int p[4000000]; //parent of participants
int st[4000000]; //size of people

map<string, int> repeat;
//stores (bank no, credit no, device) and the latest person to use

int parent(int x){
	if (p[x] == x) return x;
	return p[x] = parent(p[x]);
}

void merge_parent(int x, int y){
	x = parent(x);
	y = parent(y);
	if (x == y) return;
	if (st[y] < st[x]) swap(x, y);
	p[x] = y;
	st[y] += st[x];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	bank.open("bank_accounts.csv", ios::in);
	credit.open("credit_cards.csv", ios::in);
	device.open("devices.csv", ios::in);
	order.open("orders.csv", ios::in);
	answer.open("answer.csv", ios::out);
	
	string line, word;
	while (device >> line){
		row.clear();
		stringstream s(line);
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		if (row[0] == "userid") continue;
		if (m.find(row[0]) == m.end()){
			m[row[0]] = counter;
			p[counter] = counter;
			st[counter] = 1;
			counter++;
		}
		if (repeat.find(row[1]) == repeat.end()){
			repeat[row[1]] = m[row[0]];
		} else {
			merge_parent(repeat[row[1]], m[row[0]]);
		}
	}
	device.clear();
	device.seekg(0, ios::beg);
	repeat.clear();
	
	while (bank >> line){
		row.clear();
		stringstream s(line);
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		if (row[0] == "userid") continue;
		if (m.find(row[0]) == m.end()){
			m[row[0]] = counter;
			p[counter] = counter;
			st[counter] = 1;
			counter++;
		}
		if (repeat.find(row[1]) == repeat.end()){
			repeat[row[1]] = m[row[0]];
		} else {
			merge_parent(repeat[row[1]], m[row[0]]);
		}
	}
	bank.clear();
	bank.seekg(0, ios::beg);
	repeat.clear();
	
	while (credit >> line){
		row.clear();
		stringstream s(line);
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		if (row[0] == "userid") continue;
		if (m.find(row[0]) == m.end()){
			m[row[0]] = counter;
			p[counter] = counter;
			st[counter] = 1;
			counter++;
		}
		if (repeat.find(row[1]) == repeat.end()){
			repeat[row[1]] = m[row[0]];
		} else {
			merge_parent(repeat[row[1]], m[row[0]]);
		}
	}
	credit.clear();
	credit.seekg(0, ios::beg);
	repeat.clear();

	answer << "orderid,is_fraud\n";
	while (order >> line){
		row.clear();
		stringstream s(line);
		while (getline(s, word, ',')){
			row.push_back(word);
		}
		if (row[0] == "orderid") continue;
		answer << row[0] << ",";
		if (m.find(row[1]) == m.end() || m.find(row[2]) == m.end()){
			answer << (int)(row[1] == row[2]) << "\n";
			continue;
		}
		answer << (int)(parent(m[row[1]]) == parent(m[row[2]])) << "\n";
	}
	
	
	bank.close();
	credit.close();
	device.close();
	order.close();
	answer.close();
	
}
	
