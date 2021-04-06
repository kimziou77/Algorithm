#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <ctime>
using namespace std;
int N, M, K;
int A[11][11];
int map[11][11];
using pii = pair<int, int>;
deque<int> trees[11][11];//좌표값과 나이를 저장할 큐
vector<int> die;
void life(int year);

void spring_summer();
void autumn();
void winter();

int dr[] = { -1,-1,-1,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };
int answer = 0;
int main(void) {
	printf("software engineering homework test1");
	//freopen("input.txt", "r", stdin);
	printf("test user2");
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;	cin >> a >> b >> c;
		trees[a][b].push_back(c);
		answer++;
	}

	life(K);

	return 0;
}
void life(int year) {
	if (year == 0) {
		printf("%d", answer);
		return;
	}
	spring_summer();
	autumn();
	winter();
	life(year - 1);
}
void spring_summer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int eng = 0;
			int num = 0;
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (map[i][j] < trees[i][j][k]) {
					eng += trees[i][j][k] / 2;
					answer--;
					num++;
				}
				else {
					map[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
				}
			}
			map[i][j] += eng;

			while (num--)
				trees[i][j].pop_back();
		}
	}
}

void autumn() {
	char nr, nc;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k] % 5 == 0) {
					for (int x = 0; x < 8; x++) {
						nr = i + dr[x];
						nc = j + dc[x];
						if (nr<1 || nc<1 || nr>N || nc>N) continue;
						trees[nr][nc].push_front(1);
						answer++;
					}
				}
			}
		}
	}

}
void winter() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] += A[i][j];
}