#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 101;
int testCases, len, limitVal, seq[MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE];

bool isRepeating(int s, int e) {
    int segment = e - s + 1;
    for (int sub = 1; sub <= segment / 2; sub++) {
        if (segment % sub == 0) {
            bool valid = true;
            for (int i = s; i <= e - sub; i++) {
                if (seq[i] != seq[i + sub]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
    }
    return false;
}

int compute(int s, int e) {
    if (s > e) return 0;
    if (memo[s][e] != -1) return memo[s][e];
    if (s == e) return memo[s][e] = 1;
    int best = e - s + 1;
    for (int mid = s; mid < e; mid++) {
        best = min(best, compute(s, mid) + compute(mid + 1, e));
    }
    if (isRepeating(s, e)) {
        int segment = e - s + 1;
        for (int sub = 1; sub <= segment / 2; sub++) {
            if (segment % sub == 0) {
                bool valid = true;
                for (int i = s; i <= e - sub; i++) {
                    if (seq[i] != seq[i + sub]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) best = min(best, compute(s, s + sub - 1));
            }
        }
    }
    return memo[s][e] = best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> testCases;
    while(testCases--){
        cin >> len >> limitVal;
        for (int i = 1; i <= len; i++) cin >> seq[i];
        memset(memo, -1, sizeof(memo));
        int result = compute(1, len);
        cout << (result <= limitVal ? "YES" : "NO") << "\n";
    }
    return 0;
}
