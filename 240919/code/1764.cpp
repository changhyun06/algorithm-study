#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {

	int n, m;
	map<string, int> map;
	string s;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		map[s] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;

		if (map.find(s) != map.end()) {
			map.erase(s);
			map[s] = 2;
			cnt++;
		}
	}

	cout << cnt << '\n';

	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second == 2) {
			cout << it->first << '\n';
		}
	}
}