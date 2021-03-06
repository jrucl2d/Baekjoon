#include <iostream>
#include <string>
using namespace std;
#define MAX 129
int arr[MAX][MAX];
int count1 = 0;
int count0 = 0;

void func(int a, int b, int n) {
    // 탈출조건
    int num = arr[a][b];
    bool divide = false;
    for (int i = a; i < a + n; i++) {
        for (int j = b; j < b + n; j++) {
            if (arr[i][j] != num) { // 처음 숫자와 달라지면 분할
                divide = true; break;
            }
        }
    }
    if (divide) {
        n = n / 2;
        func(a, b, n);
        func(a + n, b, n);
        func(a, b + n, n);
        func(a + n, b + n, n);
        return;
    }
    // 수 세기
    if (num == 1)
        count1++;
    else 
        count0++;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    func(0, 0, n);
    cout << count0 << '\n' << count1;
}
