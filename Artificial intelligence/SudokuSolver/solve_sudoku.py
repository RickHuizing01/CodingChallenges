import time

def cross(A, B):
    '''
    concatenate of chars in string A and chars in string B
    '''
    return [a+b for a in A for b in B]

digits = '123456789'
rows = 'ABCDEFGHI'
cols = digits
cells = cross(rows, cols)  # 81 cells A1..9, B1..9, C1..9, ...

# unit = a row, a column, a box; list of all units
unit_list = (
    [cross(r, cols) for r in rows] + 
    [cross(rows, c) for c in cols] +
    [cross(rs, cs) for rs in ('ABC', 'DEF', 'GHI') for cs in ('123', '456', '789')]
)

units = dict((s, [u for u in unit_list if s in u]) for s in cells)
peers = dict((s, set(sum(units[s], []))-set([s])) for s in cells)


def display(grid):
    '''
    grid is a dict of {cell: string}, e.g. grid['A1'] = '1234'
    '''
    print()
    for r in rows:
        for c in cols:
            v = grid[r+c]
            if v == '123456789':
                v = '.'
            print(''.join(v), end=' ')
            if c == '3' or c == '6':
                print('|', end='')
        print()
        if r == 'C' or r == 'F':
            print('-------------------')
    print()


def parse_string_to_dict(grid_string):
    '''
    grid_string is a string like '4.....8.5.3..........7......2.....6....   '
    convert grid_string into a dict of {cell: chars}
    '''

    char_list1 = [c for c in grid_string if c in digits or c == '.']
    assert len(char_list1) == 81
    char_list2 = [s.replace('.', '123456789') for s in char_list1]
    return dict(zip(cells, char_list2))


def no_conflict(grid, c, val):
    # check if assignment is possible: value v not a value of a peer
    for p in peers[c]:
        if grid[p] == val:
            return False  # conflict
    return True


def is_finished(grid):
    for value in grid.values():
        if len(value) > 1:
            return False
    return True


def get_next_cell(grid):
    filtered = filter(lambda item: len(item[1]) > 1, grid.items())
    return min(filtered, key=lambda item: len(item[1]))[0] 


def get_all_cells_with_one_value(grid):
    return list(filter(lambda item: len(item[1]) == 1, grid.items()))


def make_arc_consistent(grid, cell, value):
    changed = False
    for peer in peers[cell]:
        peer_domain = list(grid[peer])
        if value in peer_domain:
            if len(peer_domain) <= 1:
                return False
            else:
                peer_domain.remove(value)
                grid[peer] = "".join(peer_domain)
                changed = True
    if changed:
        for c2 in get_all_cells_with_one_value(grid):
            if not make_arc_consistent(grid, c2[0], c2[1]):
                return False
    return True


def solve(grid):
    if is_finished(grid):
        display(grid)
        return True

    next_key = get_next_cell(grid)

    for value in list(grid[next_key]):
        if no_conflict(grid, next_key, value):
            new_grid = grid.copy()
            new_grid[next_key] = value

            if make_arc_consistent(new_grid, next_key, value):
                if solve(new_grid):
                    return True
    return False

sudokuList = [None for _ in range(20)]
sudokuList[0] = '.56.1.3....16....589...7..4.8.1.45..2.......1..42.5.9.1..4...899....16....3.6.41.'
sudokuList[1] = '.6.2.58...1....7..9...7..4..73.4..5....5..2.8.5.6.3....9.73....1.......93......2.'
sudokuList[2] = '.....9.73.2.....569..16.2.........3.....1.56..9....7...6.34....7.3.2....5..6...1.'
sudokuList[3] = '..1.3....5.917....8....57....3.1.....8..6.59..2.9..8.........2......6...315.9...8'
sudokuList[4] = '....6.8748.....6.3.....5.....3.4.2..5.2........72...35.....3..........69....96487'
sudokuList[5] = '.94....5..5...7.6.........71.2.6.........2.19.6...84..98.......51..9..78......5..'
sudokuList[6] = '.5...98..7...6..21..2...6..............4.598.461....5.54.....9.1....87...2..5....'
sudokuList[7] = '...17.69..4....5.........14.....1.....3.5716..9.....353.54.9....6.3....8..4......'
sudokuList[8] = '..6.4.5.......2.3.23.5..8765.3.........8.1.6.......7.1........5.6..3......76...8.'
sudokuList[9] = '4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......'
sudokuList[10] = '85...24..72......9..4.........1.7..23.5...9...4...........8..7..17..........36.4.'
sudokuList[11] = '...5....2...3..85997...83..53...9...19.73...4...84...1.471..6...5...41...1...6247'
sudokuList[12] = '.....6....59.....82....8....45........3........6..3.54...325..6..................'
sudokuList[13] = '4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......'
sudokuList[14] = '8..........36......7..9.2...5...7.......457.....1...3...1....68..85...1..9....4..'
sudokuList[15] = '6..3.2....5.....1..........7.26............543.........8.15........4.2........7..'
sudokuList[16] = '.6.5.1.9.1...9..539....7....4.8...7.......5.8.817.5.3.....5.2............76..8...'
sudokuList[17] = '..5...987.4..5...1..7......2...48....9.1.....6..2.....3..6..2.......9.7.......5..'
sudokuList[18] = '3.6.7...........518.........1.4.5...7.....6.....2......2.....4.....8.3.....5.....'
sudokuList[19] = '1.....3.8.7.4..............2.3.1...........958.........5.6...7.....8.2...4.......'

begin = time.time()

for index, sudoku in enumerate(sudokuList):
    print('*** sudoku {0} ***'.format(index))
    print(sudoku)

    d = parse_string_to_dict(sudoku)
    start_time = time.time()
    solve(d)
    end_time = time.time()

    hours, rem = divmod(end_time-start_time, 3600)
    minutes, seconds = divmod(rem, 60)
    print("duration [hh:mm:ss.ddd]: {:0>2}:{:0>2}:{:06.3f}".format(
        int(hours), int(minutes), seconds))


end = time.time()
hours, rem = divmod(end-begin, 3600)
minutes, seconds = divmod(rem, 60)
print("total duration [hh:mm:ss.ddd]: {:0>2}:{:0>2}:{:06.3f}".format(
    int(hours), int(minutes), seconds))


"""
Total time
before arc-consistency: 3:43
after arc-consistency: 0:07
"""
