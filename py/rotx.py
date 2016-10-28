#rot3 decrypt scrypt
#writen by s8_ken
#2016/10/28

# -*- coding; utf-8 -*-

def _rot3(x,c):
    if 'A' <= c and c <= 'Z':
        return chr((ord(c) - ord('A') + x) % 26 + ord('A'))

    if 'a' <= c and c <= 'z':
        return chr((ord(c) - ord('a') + x) % 26 + ord('a'))

    return c

def rot3(x,s):
    g = ''
    for c in s:
        g =g + _rot3(x,c)

    return g

def main():
    print "rot? : "
    x = int(raw_input())
    print "cypher text ? : "
    s = raw_input()
    print(rot3(x,s))


if __name__=='__main__':
    main()

