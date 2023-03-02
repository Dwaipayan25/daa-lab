class treasure:
    def __init__(self,grid,order):
        self.grid = grid
        self.order = order
        self.dp = [[0]*order]*order
    def getMaxTreasure(self):
        for i in range(self.order):
            for j in range(self.order):
                if i==0 and j==0:
                    self.dp[0][0]=self.grid[0][0]
                elif i==0 and j!=0:
                    self.dp[i][j]=self.grid[i][j]+self.dp[i][j-1]
                elif i!=0 and j==0:
                    self.dp[i][j]=self.grid[i][j]+self.dp[i-1][j]
                else:
                    self.dp[i][j]=self.grid[i][j]+max(self.dp[i-1][j],self.dp[i][j-1])
        return self.dp[self.order-1][self.order-1]
    
# grid = [[4,8,3,6,1],
#         [9,7,2,5,11],
#         [5,9,2,4,1],
#         [7,1,3,6,5],
#         [4,1,2,4,5]]

grid = [[1,7],
        [5,2]]

ob = treasure(grid,2)
print("Maximum treasure collected: {}".format(ob.getMaxTreasure()))