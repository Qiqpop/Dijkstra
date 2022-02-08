#include <iostream>
#define inf INT_MAX


using namespace std;

void Dijkstra(bool* v, int* d, int** arr, int N) {

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

int main() {
	setlocale(0, "");
	int N, M;
	cin >> N >> M;

	//Посещенные вершины
	bool* v = new bool[N];
	for (int i = 0; i < N; i++) {
		v[i] = 0;
	}

	//Создание таблицы смежности, инициализация нулями, заполнение
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	//Вычисление длинны до ребер, вывод
	int *d = new int[N];
	d[0] = 0;
	for (int i = 1; i < N; i++) {
		d[i] = inf;
	}
	Dijkstra(v, d, arr, N);
	cout << endl << endl;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << ' ' << d[i] << endl;
	}


	//Удаление динамических массивов
	delete[] v;
	delete[] d;
	for (int i = 0; i < N; i++) {
		delete[] arr[i];
	}
	return 0;
}
