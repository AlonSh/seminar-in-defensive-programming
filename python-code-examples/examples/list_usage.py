# Different ways of defining a list with items 0,1,2 and 3:
a = [0, 1, 2, 3]
b = list(range(4))
c = [i for i in a]

print(f'a: {a}\nb: {b}\nc: {c}')

# Useful list operations:
print(f'The list with reversed values: {reversed(a)}')
print(f'The list [3,1,4,2,0] sorted: {sorted([3, 1, 4, 2, 0])}')
print(f'Every item in the list in an odd index: {a[1::2]}')
