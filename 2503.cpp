#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	int n = 0; // �� �� �Է��Ұ���
	cin >> n;
	int num = 0; // ���ھ߱��� ����
	int strike = 0;
	int ball = 0;
	int tStr = 0; // üũ�� strike
	int tBall = 0;
	int result = 0;
	string testNum;
	string temp;
	string aaa;

	bool ans[1000]; // ������ ��� �迭
	for (int i = 0; i < 1000; i++) {
		ans[i] = true; // true�� �ʱ�ȭ
	}
	
	// 123~987���� ���ǿ� �´� ���ڸ� �迭�� ��Ƶα� (0�� �ƴϰ� �� �ڸ��� ���ڰ� ������ �ȵȴ�)
	for (int i = 123; i <= 987; i++) {
		temp = to_string(i);
		if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0') {
			ans[i] = false;
		}
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) {
			ans[i] = false;
		}
	}
	
	for (int l = 0; l < n; l++) {
		cin >> num >> strike >> ball; // ���� �Է¹ޱ�
		for (int i = 123; i <= 987; i++) {
			tStr = 0;
			tBall = 0;
			testNum = to_string(num);
			aaa = to_string(i);

			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (testNum[j] == aaa[k] && j == k) {
						tStr++;
					}
					else if (testNum[j] == aaa[k] && j != k) {
						tBall++;
					}
				}
			}
			if (tStr != strike || tBall != ball) {
				ans[i] = false;
			}
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (ans[i] == true)
			result++;
	}
	
	cout << result;
	
	return 0;
}