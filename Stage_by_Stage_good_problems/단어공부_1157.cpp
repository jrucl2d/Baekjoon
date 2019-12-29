#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int alpha[26] = { 0, };
	for (int i = 0; i < s.size(); i++) {
		s[i] = towlower(s[i]); // 모두 소문자로 변경	
		alpha[s[i] - 'a']++;
	}
	int max = 0;
	int maxIndex = 0;
	for(int i = 0 ; i < 26; i++)
		if (max < alpha[i]) { max = alpha[i]; maxIndex = i; } // max 찾기
	int alone = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max) alone++;
	}
	if (alone >= 2) cout << "?";
	else if (alone == 1) cout << char(maxIndex + 'A');

}