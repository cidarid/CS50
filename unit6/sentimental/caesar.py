from cs50 import get_string
from string import ascii_lowercase as lc
from string import ascii_uppercase as uc
import sys

if (len(sys.argv) != 2):
    sys.exit(1)

cipher = int(sys.argv[1])
s = get_string("plaintext: ")
ns = ''
i = 0
for c in s:
    if c in lc:
        ns = ns + lc[(lc.index(c)+cipher) % len(lc)]
    elif c in uc:
        ns = ns + uc[(uc.index(c)+cipher) % len(uc)]
    else:
        ns += c
print("ciphertext: " + ns)