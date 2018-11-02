# Different ways of defining a dict from ABC letters to their ascii code:
a = {'A': ord('A'), 'B': ord('B'), 'C': ord('C')}
b = {letter: ord(letter) for letter in 'ABCDEFG'}
c = dict([('D', ord('D')), ('E', ord('E')), ('F', ord('F'))])

print(f'a: {a}\nb: {b}\nc: {c}')

# Useful dict operations:
print(f'\nKeys of b as list: {list(b.keys())}')
print('Translation of key "B" to value: {}'.format(b['B']))

print('\nBinary tree represented as a dict:')
print({'root': {'value': 5, 'left': {'value': 6, 'left': None, 'right': None},
                'right': {'value': 7, 'left': None, 'right': None}}})
