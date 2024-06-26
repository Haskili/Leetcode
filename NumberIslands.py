def explore(y, x, grid, grouping, mapping):
    """
    A recursive solution to slowly increment 'groupping',
    the counter of total islands seen, by utilizing a map
    'mapping' and the input 'grid'.

    The function looks in all directions recursively.

    Arguments:
            y (str): The current y value of the coordinate
            x (str): The current x value of the coordinate
            grid (list[list[int]]): The input array from caller
            grouping (int): The current island number
            mapping (dict): A map to track what coordinates have
                            been seen prior to this call

    Returns:
            N/A

    Raises:
            N/A
    """
    
    # Mark the current position
    mapping[(y, x)] = grouping

    # Check above, below, left, and right of the current
    # coordinates '(y, x)';
    #
    # Before exploring in that direction make sure that
    # A) The coordinates are valid
    # B) The value is an island within 'grid'
    # C) We haven't seen '(y, x)' in a previous 'explore()' call
    #    as dictated by 'mapping'

    # Check above
    if ((y - 1) >= 0) and (grid[y - 1][x] == "1") and ((y - 1, x) not in mapping):
        explore(y - 1, x, grid, grouping, mapping)

    # Check below
    if ((y + 1) < len(grid)) and (grid[y + 1][x] == "1") and ((y + 1, x) not in mapping):
        explore(y + 1, x, grid, grouping, mapping)

    # Check left
    if ((x - 1) >= 0) and (grid[y][x - 1] == "1") and ((y, x - 1) not in mapping):
        explore(y, x - 1, grid, grouping, mapping)

    # Check right
    if ((x + 1) < len(grid[0])) and (grid[y][x + 1] == "1") and ((y, x + 1) not in mapping):
        explore(y, x + 1, grid, grouping, mapping)


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        # Define the input space of 'grid', and initialize
        # a counter value to tell how many connected groups
        # have been seen inside the for-loop below
        rows = len(grid)
        columns = len(grid[0])
        grouping = 0

        # Create a mapping for found island tiles
        # and their related group
        mapping = {}

        # Iterate through each tile in 'grid'
        for y in range(rows):
            for x in range(columns):

                # If the tile at '(y, x)' hasn't been seen yet 
                # and it's a land tile, explore() starting from
                # (y, x) as an entirely new group of connnected land
                if grid[y][x] == "1" and (y, x) not in mapping:
                    explore(y, x, grid, grouping, mapping)
                    grouping += 1

        # Return the amount of times we found 
        # a unique point to start an island from
        return grouping