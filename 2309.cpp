/*
접근법	1. 난쟁이 7명 키의 합이 100이므로 입력받은 숫자를 일단 다 더한다.
		2. 전체 - (난쟁이 아닌 2명의 키의 합) == 100
		3. 이중 for문으로 배열 전체 검사후, sort 이용해서 결과 출력
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	int sum = 0;
	int digitNum = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		sum = i;
		digitNum = i;

		while (digitNum) {
			sum += digitNum % 10;
			digitNum /= 10;
		}

		if (sum == n) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0;
	return 0;
}