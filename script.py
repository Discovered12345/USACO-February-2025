grid_size, num_updates = map(int, input().split())
mid = grid_size // 2
grid = [[None] * (grid_size + 2) for _ in range(grid_size + 2)]
for row in range(1, grid_size + 1):
    line = input().strip()
    for col in range(1, grid_size + 1):
        grid[row][col] = line[col - 1]
contribution = [[0] * (grid_size + 2) for _ in range(grid_size + 2)]
total_contribution = 0

for origin_row in range(1, mid + 1):
    for origin_col in range(mid + 1, grid_size + 1):

        cell_a_row, cell_a_col = origin_row, origin_col
        cell_b_row, cell_b_col = (grid_size + 1) - origin_row, origin_col
        cell_c_row, cell_c_col = origin_row, (grid_size + 1) - origin_col
        cell_d_row, cell_d_col = (grid_size + 1) - origin_row, (grid_size + 1) - origin_col
        

        painted_count = 0
        if grid[cell_a_row][cell_a_col] == '#':
            painted_count += 1
        if grid[cell_b_row][cell_b_col] == '#':
            painted_count += 1
        if grid[cell_c_row][cell_c_col] == '#':
            painted_count += 1
        if grid[cell_d_row][cell_d_col] == '#':
            painted_count += 1
        

        group_contribution = min(painted_count, 4 - painted_count)
        contribution[origin_row][origin_col] = group_contribution
        total_contribution += group_contribution


print(total_contribution)


for _ in range(num_updates):
    update_row, update_col = map(int, input().split())
    

    current_state = grid[update_row][update_col]
    grid[update_row][update_col] = '.' if current_state == '#' else '#'
    

    if update_row <= mid:
        origin_row = update_row
    else:
        origin_row = (grid_size + 1) - update_row
    
    if update_col > mid:
        origin_col = update_col
    else:
        origin_col = (grid_size + 1) - update_col
    

    cell_a_row, cell_a_col = origin_row, origin_col
    cell_b_row, cell_b_col = (grid_size + 1) - origin_row, origin_col
    cell_c_row, cell_c_col = origin_row, (grid_size + 1) - origin_col
    cell_d_row, cell_d_col = (grid_size + 1) - origin_row, (grid_size + 1) - origin_col
    painted_count = 0
    if grid[cell_a_row][cell_a_col] == '#':
        painted_count += 1
    if grid[cell_b_row][cell_b_col] == '#':
        painted_count += 1
    if grid[cell_c_row][cell_c_col] == '#':
        painted_count += 1
    if grid[cell_d_row][cell_d_col] == '#':
        painted_count += 1
    new_group_contribution = min(painted_count, 4 - painted_count)
    total_contribution += (new_group_contribution - contribution[origin_row][origin_col])
    contribution[origin_row][origin_col] = new_group_contribution
    
    print(total_contribution)