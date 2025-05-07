class MinStack:
    def __init__(self):
        self._st = []
        self._min = []
        self._count = 0

    def push(self, val: int) -> None:
        if self._count == 0:
            self._min.append(val)
        elif self._min[-1] > val:
            self._min.append(val)
        else:
            self._min.append(self._min[-1])
            
        self._count += 1
        self._st.append(val)
        

    def pop(self) -> None:
        self._count -= 1
        self._st.pop()
        self._min.pop()
        

    def top(self) -> int:
        return self._st[-1]
        

    def getMin(self) -> int:
        return self._min[-1]