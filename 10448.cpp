#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	int n = 0; // 테스트 케이스의 갯수
	int sum = 0; // 삼각합
	int triangle[44]; // 삼각합을 담을 배열
	int chk = 0;

	cin >> n;
	int* test = (int*)malloc(sizeof(int) * n); // 테스트 케이스

	for (int i = 0; i < n; i++) {
		cin >> test[i];
	}

	for (int i = 1; i < 45; i++) {
		sum += i;
		triangle[i-1] = sum;
	}
	for (int m = 0; m < n; m++) {
		chk = 0;
		for (int i = 0; i < 45; i++) {
			if (chk == 1) {
				break;
			}
			for (int j = 0; j < 45; j++) {
				if (chk == 1) {
					break;
				}
				for (int k = 0; k < 45; k++) {
					if (triangle[i] + triangle[j] + triangle[k] == test[m]) {
						cout << 1 << '\n';
						chk = 1;
						break;
					}
				}
			}
		}
		if (chk == 0) {
			cout << 0 << " m은" << m <<  '\n';
		}
	}
	
	free(test);
	return 0;
}