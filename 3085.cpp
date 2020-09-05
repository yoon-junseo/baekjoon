#include <iostream>
#include <algorithm>
using namespace std;

int n;
char arr[50][50];

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

int check() {
	int same = 1;
	int result = 1;

	for (int i = 0; i < n; i++) {
		same = 1;
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				same++;
			}
			else {
				result = max(result, same);
				same = 1;
			}
		}
		result = max(result, same);
	}
	for (int i = 0; i < n; i++) {
		same = 1;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j][i] == arr[j + 1][i]) {
				same++;
			}
			else {
				result = max(result, same);
				same = 1;
			}
		}
		result = max(result, same);
	}
	return result;
}

int main() {
	int result = 1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			result = max(result, check());
			swap(arr[i][j], arr[i][j + 1]);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			swap(arr[i][j], arr[i + 1][j]);
			result = max(result, check());
			swap(arr[i][j], arr[i + 1][j]);
		}
	}

	cout << result << '\n';

	return 0;
}
