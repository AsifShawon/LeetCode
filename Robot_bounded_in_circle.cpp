class Solution {
public:
    bool isRobotBounded(string instructions) {
        char c, dir = 'N';
        int x = 0, y = 0;
        for (int i = 0; i < instructions.length(); i++) {
            c = instructions[i];
            if (c == 'G') {
                switch (dir) {
                case 'N':
                    y++;
                    break;
                case 'W':
                    x--;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                }
            }

            else if (c == 'L') {
                switch (dir) {
                case 'N':
                    dir = 'W';
                    break;
                case 'W':
                    dir = 'S';
                    break;
                case 'S':
                    dir = 'E';
                    break;
                case 'E':
                    dir = 'N';
                    break;
                }
            } else if (c == 'R') {
                switch (dir) {
                case 'N':
                    dir = 'E';
                    break;
                case 'W':
                    dir = 'N';
                    break;
                case 'S':
                    dir = 'W';
                    break;
                case 'E':
                    dir = 'S';
                    break;
                }
            }
        }

        return (x == 0 and y == 0) or dir != 'N';
    }
};

// https://leetcode.com/problems/robot-bounded-in-circle/

// 0 ms