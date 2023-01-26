#include <iostream>
#include <vector>
#define inf INT_MAX


using namespace std;

//Алгоритм Дейкстры
void Dijkstra(vector <bool>& v, vector <int>& d, vector <vector<int>>& arr, int N);

int main() {
	// Корректный вывод кирилицы
	setlocale(0, "ru");
	
	int N, M;
	cin >> N >> M;

	//Посещенные вершины
	vector <bool> v(N, 0);

	//Создание и заполнение таблицы смежности
	vector <vector<int>> arr(N, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	//Вычисление длинны до ребер, вывод
	vector <int> d(N, 0);
	for (int i = 1; i < N; i++) {
		d[i] = inf;
	}
	Dijkstra(v, d, arr, N);
	cout << endl << endl;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << ' ' << d[i] << endl;
	}
	return 0;
}

void Dijkstra(vector <bool> &v, vector <int> &d, vector <vector<int>> &arr, int N) {
	//Алгоритм Дейкстры
	int ind = inf, mini = inf;
	do {
		ind = inf, mini = inf;
		for (int i = 0; i < N; i++) {
			if (!v[i] && d[i] < mini) {
				ind = i;
				mini = d[i];
			}
		}
		if (ind != inf) {
			for (int i = 0; i < N; i++) {
				if (arr[ind][i] != 0 && (d[i] > d[ind] + arr[ind][i])) {
					d[i] = d[ind] + arr[ind][i];
				}
			}
			v[ind] = 1;
		}
		else return;
	} while (1);
}
