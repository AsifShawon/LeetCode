class Solution {
public:
    int myAtoi(string s) {
        int dot = 0, neg = 0, pos = 0, space = 0, count = 0, divdot = 10;
        bool no_neg = true;
        long long int MAX_INT = 2147483647;
        long long int MIN_INT = -2147483648;
        long long int ans = 0;
        // acceptable characters -> 0-9, -, . , " ", +
        for (int i = 0; i < s.size(); i++) {
            // cout << s[i] << " " << (!(s[i] >= '0' and s[i] <= '9')) << endl;
            if (!(s[i] >= '0' and s[i] <= '9') and s[i] != '-' and
                s[i] != '+' and s[i] != '.' and s[i] != ' ') {
                break;
            }
            // s[i] = 0-9, ' ', -, +, .
            if (s[i] >= '0' and s[i] <= '9') {
                // neg++;
                // pos++;
                count++;
                ans = ans * 10 + (s[i] - '0');

                // cout << ans << endl;
                if (ans > MAX_INT and neg < 1) {
                    ans = MAX_INT;
                } else if (ans > MAX_INT and neg == 1) {
                    ans = MIN_INT;
                }
                if (ans < MIN_INT) {
                    ans = MIN_INT;
                }
            } else { // s[i] = ' ', -, +, .
                if (s[i] == ' ' and !(count > 0)) {
                    space = 1;
                    if(pos > 0 or neg > 0 or dot > 0){
                        break;
                    }
                } else if (s[i] == ' ' and (count > 0)) {
                    break;
                } else if (s[i] == '+') {
                    pos++;
                    if (pos > 1) {
                        break;
                    }
                } else if (s[i] == '-') {
                    neg++;
                    if (neg > 1) {
                        break;
                    }
                } else if (s[i] == '.') {
                    break;
                }
                if (pos > 0 and neg > 0) {
                    break;
                }
                if (count > 0 and (neg > 0 or pos > 0 or dot > 0)) {
                    no_neg = false;
                    break;
                }
            }
        }
        // cout << neg;
        if (neg > 0 and no_neg) {
            ans *= -1;
        }
        return ans;
    }
};