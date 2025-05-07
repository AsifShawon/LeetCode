from typing import List
class Solution:
    def reset(self) -> List[int]:
      num_list = [0,0,0,0,0,0,0,0,0,0]
      return num_list

    def isValidSudoku(self, board: List[List[str]]) -> bool:
      result = False

      # row check
      for row in board:
        li = self.reset()
        for item in row:
          # print(item)
          if item != '.':
            li[(ord(item)-ord('0'))-1] += 1

        if max(li) > 1:
          return False

      # transpose
      trans = [[0 for _ in range(9)] for _ in range(9)] # creating a matrix named 'trans' with initiating all value to 0

      for row in range(9):
        for col in range(9):
          trans[col][row] = board[row][col]

      # column check
      for row in trans:
        li = self.reset()
        for item in row:
          # print(item)
          if item != '.':
            li[(ord(item)-ord('0'))-1] += 1

        if max(li) > 1:
          return False

      # each 3*3 matrix check
      # li = [[0 for _ in range(9)] for _ in range(9)]
      start_row = 0
      end_row = 3
      start_col = 0
      end_col = 3
      for row in range(0,9):
        # print(start_row, end_row, start_col, end_col)
        li = self.reset()
        for i in range(start_row,end_row):
          for j in range(start_col,end_col):
            # print(board[i][j],end=" ")
            if board[i][j] != '.':
              li[((ord(board[i][j])-ord('0')))-1] += 1
          # print("--2--")
        if max(li) > 1:
          return False
        start_col += 3
        end_col += 3
        if end_col >= 12:
          start_row += 3
          end_row += 3
          start_col = 0
          end_col = 3



      return True

