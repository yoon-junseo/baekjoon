/*
���ٹ�	1. ������ 7�� Ű�� ���� 100�̹Ƿ� �Է¹��� ���ڸ� �ϴ� �� ���Ѵ�.
		2. ��ü - (������ �ƴ� 2���� Ű�� ��) == 100
		3. ���� for������ �迭 ��ü �˻���, sort �̿��ؼ� ��� ���
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