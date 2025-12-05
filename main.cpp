#include <iostream>

int main()
{
    using BigNumber = uint64_t;

    constexpr int DIGITS_NUMBER = 6;
    constexpr int DIGITS_SUM = 72;
    constexpr int RADIX = 13;

    BigNumber table[DIGITS_NUMBER + 1][DIGITS_SUM + 1] = {0};
    table[0][0] = 1;

    for (int i = 1; i <= DIGITS_NUMBER; i++) {
        for (int j = 0; j <= DIGITS_SUM; j++) {
            for (int d = 0; d < RADIX; d++) {
                if (j - d >= 0) {
                    table[i][j] += table[i - 1][j - d];
                }
            }
        }
    }

    BigNumber result = 0;

    for (int i = 0; i <= DIGITS_SUM; i++) {
        BigNumber count = table[DIGITS_NUMBER][i];
        result += count * count;
    }

    result *= RADIX;

    std::cout << result << std::endl;

    return 0;
}

