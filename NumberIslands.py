def explore(y, x, grid, grouping, mapping):
    """
    ...
    """
    
    # Mark the current position
    mapping[(y, x)] = grouping

    # Check upwards
    if ((y - 1) >= 0) and (grid[y - 1][x] == "1") and ((y - 1, x) not in mapping):
        explore(y - 1, x, grid, grouping, mapping)

    # Check downwards
    if ((y + 1) < len(grid)) and (grid[y + 1][x] == "1") and ((y + 1, x) not in mapping):
        explore(y + 1, x, grid, grouping, mapping)

    # Check to the left
    if ((x - 1) >= 0) and (grid[y][x - 1] == "1") and ((y, x - 1) not in mapping):
        explore(y, x - 1, grid, grouping, mapping)

    # Check to the right
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

                # If the tile at (y, x) hasn't been seen yet 
                # and it's a land tile, explore() starting from
                # (y, x) as an entirely new group of connnected land
                if grid[y][x] == "1" and (y, x) not in mapping:
                    explore(y, x, grid, grouping, mapping)
                    grouping += 1

        # Return the amount of times we found 
        # a unique point to start an island from
        return grouping