# -*- coding; utf-8 -*-

def _rot3(c):
    if 'A' <= c and c <= 'Z':
        return chr((ord(c) - ord('A') + 3) % 26 + ord('A'))

    if 'a' <= c and c <= 'z':
        return chr((ord(c) - ord('a') + 3) % 26 + ord('a'))

    return c

def rot3(s):
    g = ''
    for c in s:
        g =g + _rot3(c)

    return g

def main():
    s = raw_input()
    print(rot3(s))


if __name__=='__main__':
    main()

    
    

