class fibonacci:
    def __init__(self):
        self.dp={}
        pass

    def fib(self, n):
        if n==0:
            return 0
        elif n==1:
            return 1
        else:
            if self.dp.get(n)==None:
                res = self.fib(n-1)+self.fib(n-2)
                self.dp[n]=res
                return res
            else:
                return self.dp.get(n)

ob = fibonacci()
for i in range(10):
    print("{}".format(ob.fib(i)))