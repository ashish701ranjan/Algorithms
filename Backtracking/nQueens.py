def isSafe(x, y, board, size):
    #things to check
    #1. checkLeft, 2. CheckUp, 3. checkLeftUpperDiag, 4. checkRightUpperDiagonal
    # checking left
    for i in range(y + 1):
        if board[x][i] == 1:
            return False

    # checking Up
    for i in range(x + 1):
        if board[i][y] == 1:
            return False

    # checking leftUpperDiag
    i = x
    j = y
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i = i -1
        j = j -1

    #checking RightUpperDiag
    i = x
    j = y
    while i >= 0 and j < size:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j + 1

    # if you have reached here, your curent position is safe
    return True

# call this recursively, fill one row in each stack
def solve(rowNumber, board, size):
    # this is the base condition, if you are here, you have got the correct arrangement
    if  rowNumber >= size:
        return True

    # this loop will look for all possible columns in a particular row
    for i in range(size):
        if isSafe(rowNumber, i, board, size):
            board[rowNumber][i] = 1
            if solve(rowNumber + 1, board, size):
                return True
            else:
                board[rowNumber][i] = 0
        # if it is not safe then thats fine, go to the next column, when all the columns are exhausted, return false
    return False

# really required?
if __name__ == "__main__":
    print "Welcome to N Queens Problem"
    size = int(raw_input("Enter the Board Size"))
    board =  [[0 for i in range(size)] for j in range(size)]
    if solve(0, board, size):
        print "solution found"
        for i in range(len(board)):
            print board[i]
    else:
        print "No Solution Exists"