def isValid(i, j, N, M):
    if i >= N or i < 0:
        return False

    if j >= M or j < 0:
        return False 

    return True


def search(board, connected, i, j, N, M):

    # Early exit condition, we've already been here
    if connected[i][j] == 1:
        return

    # Mark the current point '(i, j)' as
    # '1' in 'connected', since the caller 
    # has to have been connected to get here
    if board[i][j] == 'O':
        connected[i][j] = 1

    # Look above, below, left, and right for
    # adjacent squares:
    #
    #   - If you find a square, check it's
    #     value inside of 'board'
    #
    #   - If said value is 'O', then call
    #     self recursively on that position
    
    # Search above
    if isValid(i - 1, j, N, M) and board[i - 1][j] == 'O':
        search(board, connected, i - 1, j, N, M)

    # Search below    
    if isValid(i + 1, j, N, M) and board[i + 1][j] == 'O':
        search(board, connected, i + 1, j, N, M)
    
    # Search left
    if isValid(i, j - 1, N, M) and board[i][j - 1] == 'O':
        search(board, connected, i, j - 1, N, M)
    
    # Search right
    if isValid(i, j + 1, N, M) and board[i][j + 1] == 'O':
        search(board, connected, i, j + 1, N, M)


def DFS(board):
    """
        This solution utilizes a DFS search;

        It is a slightly slower solution than the 
        DFS implementation, and utilizes more memory. 
        This is because it utilizes a "colours" type
        matrix referred to as 'connected' to reduce
        redundant searching, requiring an extra 'N'x'M'
        space.

        Runtime: 110ms
        Memory: 17.72mb
    """

    # Define the input space of the board as 'N' x 'M'
    N, M = len(board), len(board[0])

    # Make a matrix to mark things that SHOULD NOT
    # be toggled to the off position in 'board'
    #
    #   NOTE: This will be utilized at the end
    connected = [
        [0 for column in range(M)]
        for row in range(N)
    ]

    # For the top row, bottom row, left column, and right column:
    #   - If the value at the point '(i, j)' is marked as 'O'
    #     in 'board', then call a recursive DFS function 'search(...)'
    
    # Top & Bottom row iteration
    for j in range(M):
        if (board[0][j] == 'O'):
            search(board, connected, 0, j, N, M)

        if (board[N - 1][j] == 'O'):
            search(board, connected, N - 1, j, N, M)
    
    # Left & Right column iteration
    for i in range(N):
        if (board[i][0] == 'O'):
            search(board, connected, i, 0, N, M)

        if (board[i][M - 1] == 'O'):
            search(board, connected, i, M - 1, N, M)

    # Evaluation of the connections
    for i in range(0, N):
        for j in range(0, M):
            
            # If the value at '(i, j)' in 'connected'
            # is set to '0' still, then set it to 'X'
            # inside the same position of 'board' as
            # an ocean square 'X'; Else set to 'O' 
            if connected[i][j] == 0:
                board[i][j] = 'X'
            else:
                board[i][j] = 'O'


def BFS(board):
    """
        This solution utilizes a BFS search;

        It is a slightly faster solution than the 
        DFS implementation, and utilizes less memory. 
        This is in part because it saves space by using 
        'board' itself to mark which islands should be 
        toggled or kept as a 'O' value.

        Runtime: 104ms
        Memory: 17.66mb
    """

    # Define the input space of the board as 'N' x 'M'
    N, M = len(board), len(board[0])

    # Define a queue to hold '(i, j)' style coordinates
    # that we'll use for a Breadth-First-Search style process
    Q = []

    # For the top row, bottom row, left column, and right column:
    #   - If the value at the point '(i, j)' is marked as 'O'
    #     in 'board', then add the coordinates to the queue

    # Top & Bottom row search
    for j in range(M):
        if (board[0][j] == 'O'):
            Q.append((0, j))

        if (board[N - 1][j] == 'O'):
            Q.append((N - 1, j))
    
    # Left & Right column search
    for i in range(N):
        if (board[i][0] == 'O'):
            Q.append((i, 0))

        if (board[i][M - 1] == 'O'):
            Q.append((i, M - 1))

    # Continue iterating through values
    # stored in the queue 'Q' as long
    # as is needed to exhaust coordinates
    while Q:

        # Get the current coordinates '(i, j)'
        i, j = Q.pop(0)

        # Mark the value at the coordinates in 'board'
        board[i][j] = '~'

        # Search above, below, left, and right of '(i, j)',
        # appending any squares marked as 'O' in 'board' to 'Q'
        # before marking them similar to the above statement
        
        # Above
        if isValid(i - 1, j, N, M) and board[i - 1][j] == 'O':
            Q.append((i - 1, j))
            board[i - 1][j] = '~'

        # Below
        if isValid(i + 1, j, N, M) and board[i + 1][j] == 'O':
            Q.append((i + 1, j))
            board[i + 1][j] = '~'

        # Left
        if isValid(i, j - 1, N, M) and board[i][j - 1] == 'O':
            Q.append((i, j - 1))
            board[i][j - 1] = '~'

        # Right
        if isValid(i, j + 1, N, M) and board[i][j + 1] == 'O':
            Q.append((i, j + 1))
            board[i][j + 1] = '~'
    
    # Iterate through the 'board' and alter values
    # based on the results of the markings 
    for i in range(0, N):
        for j in range(0, M):
            if board[i][j] == '~':
                board[i][j] = 'O'
            else:
                board[i][j] = 'X'

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        BFS(board)
