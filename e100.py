import sys
import functools

@functools.lru_cache(2**10)
def n3_add_1(n):
    if n == 1:
        return(1)

    if n % 2 == 1:
        return(n3_add_1(3 * n + 1) + 1)

    return(n3_add_1(n // 2) + 1)

if __name__ == "__main__":
    for line in sys.stdin:
        i, j = map(int, line.split())

        cycle_lengths = []
        for k in range(i, j + 1):
            cycle_lengths.append(n3_add_1(k))

        print(i, j, max(cycle_lengths))
