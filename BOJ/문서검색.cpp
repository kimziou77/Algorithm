#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> makeTable(string p) {
	int m = p.size();
	vector<int> table(m, 0);
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = table[j - 1];

		if (p[i] == p[j])
			table[i] = ++j;
	}
	return table;
}

int kmp(string s, string p) {
	auto table = makeTable(p);
	int parentSize = s.size();
	int patternSize = p.size();
	table[patternSize - 1] = 0;//문자열을 발견했다면 다시 0으로 돌아가야 하므로

	int j = 0;//인덱스는 0부터 시작
	int answer = 0;
	for (int i = 0; i < parentSize; i++) {//문자열 처음부터 탐색하는데

		while (j > 0 && s[i] != p[j]) //j번쨰랑 비교
			j = table[j - 1];//j값을 계속 유동적으로 변경시킨다.

		if (s[i] == p[j]) {
			if (j == patternSize - 1) { //모두 맞췃다면
				//cout << "찾은 위치 : " << i - petternSize + 1 << endl;
				j = 0;//다시 검사시작
				answer++; // 정답개수 ++
			}
			else {
				j++;
			}
		}
	}
	return answer;
}
int main(void) {
	string a; string b;
	getline(cin,a);
	getline(cin,b);

	cout<<kmp(a, b);
	
	return 0;
}