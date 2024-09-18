#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

string decimalToBase(int number, int k) {
    string result("");

    while (number > 0) {
        int remainder = number % k;
        result += to_string(remainder);

        number /= k;
    }

    reverse(result.begin(), result.end());

    return result;
}

int solution(int n, int k) {
    int answer = 0;

    string based_number = decimalToBase(n, k);
    string word = "";

    for (int idx = 0; idx < based_number.size(); ++idx) {
        // 0을 만날 때 처리
        if (based_number[idx] == '0') {
            // 숫자가 비어있지 않고, 소수인지 확인
            if (!word.empty()) {
                long long num = stoll(word);  // stoll을 사용하여 큰 숫자 처리
                if (isPrime(num)) {
                    answer++;
                }
            }

            word.clear();
            continue;
        } else {
            word += based_number[idx];
        }
    }

    // 마지막에 남은 숫자 처리
    if (!word.empty()) {
        long long num = stoll(word);  // stoll을 사용하여 큰 숫자 처리
        if (isPrime(num)) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int number = 587594768;
    int k = 8;

    cout << "Prime count: " << solution(number, k) << endl;

    return 0;
}
