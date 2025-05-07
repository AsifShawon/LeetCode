from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        value = []
        for token in tokens:
            if token not in ['+', '-', '/', '*']:
                value.append(int(token))
            else:
                num2 = value[-1]
                value.pop()
                num1 = value[-1]
                value.pop()
                if token == '+':
                    value.append(num1+num2)
                elif token == '-':
                    value.append(num1-num2)
                elif token == '*':
                    value.append(num1*num2)
                else:
                    value.append(int(num1/num2))
                    
                
        return value[-1]